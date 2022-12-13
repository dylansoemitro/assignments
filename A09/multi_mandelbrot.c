#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include <time.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include "read_ppm.h"
#include "write_ppm.h"

int main(int argc, char* argv[]) {
  int size = 480;
  float xmin = -2.0;
  float xmax = 0.47;
  float ymin = -1.12;
  float ymax = 1.12;
  int maxIterations = 1000;
  int numProcesses = 4;

  int opt;
  while ((opt = getopt(argc, argv, ":s:l:r:t:b:p:")) != -1) {
    switch (opt) {
      case 's': size = atoi(optarg); break;
      case 'l': xmin = atof(optarg); break;
      case 'r': xmax = atof(optarg); break;
      case 't': ymax = atof(optarg); break;
      case 'b': ymin = atof(optarg); break;
      case '?': printf("usage: %s -s <size> -l <xmin> -r <xmax> "
        "-b <ymin> -t <ymax> -p <numProcesses>\n", argv[0]); break;
    }
  }
  printf("Generating mandelbrot with size %dx%d\n", size, size);
  printf("  Num processes = %d\n", numProcesses);
  printf("  X range = [%.4f,%.4f]\n", xmin, xmax);
  printf("  Y range = [%.4f,%.4f]\n", ymin, ymax);
  // todo: your code here
  // generate pallet
  srand(time(0));
  //construct mandelbrot set using 4 child processes
  pid_t pid;
  int status;
  int shm_id;


  struct ppm_pixel* pallet = malloc (sizeof(struct ppm_pixel) * maxIterations);
  for (int i = 0; i < maxIterations; i++) {
    pallet[i].red = rand() % 256;
    pallet[i].green = rand() % 256;
    pallet[i].blue = rand() % 256;
  }
  //mandlebrot
  
  int shmid;
  shmid = shmget(IPC_PRIVATE, sizeof(struct ppm_pixel) * size * size, IPC_CREAT | 0666);
  if (shmid == -1){
    perror("Error: cannot initialize shared memory\n");
    exit(1);
  }
  struct ppm_pixel* shm_pixels = shmat(shmid, NULL, 0);
  if (shm_pixels == (void*)-1){
    perror("Error: cannot access shared memory\n");
    exit(1);
  }
  //Your program should use shared memory to split the computation of the image across 4 child processes. After each child completes, the parent process should save the result to a file using write_ppm.
  //process 1 row 0-240, col 0-240, process 2 row 0-240, col 240-480, process 3 row 240-480, col 0-240, process 4 row 240-480, col 240-480
  struct timeval tstart, tend;
  double timer;
  gettimeofday(&tstart, NULL);
  for(int i = 0; i < numProcesses; i++){
    pid = fork();
    if(pid == 0){
      //child process
      printf("Launched child process: %d\n", getpid());
      int startRow = (i / 2) * (size / 2);
      int endRow = startRow + (size / 2);
      int startCol = (i % 2) * (size / 2);
      int endCol = startCol + (size / 2);
      printf("%d) Sub-image block: cols (%d,%d) to rows (%d,%d)\n", getpid(), startRow, endRow, startCol, endCol);
      for (int row = startRow; row < endRow; row++) {
        for (int col = startCol; col < endCol; col++) {
          float x0 = xmin + col * (xmax - xmin) / size;
          float y0 = ymin + row * (ymax - ymin) / size;
          float x = 0.0;
          float y = 0.0;
          int iteration = 0;
          while (x*x + y*y < 2*2 && iteration < maxIterations) {
            float xtemp = x*x - y*y + x0;
            y = 2*x*y + y0;
            x = xtemp;
            iteration++;
          }
          shm_pixels[row * size + col] = pallet[iteration];
        }
      }
      exit(0);
    }
  }
  for(int i = 0; i < numProcesses; i++){
    pid = wait(&status);
    printf("Child process complete: %d\n", getpid());
  }


  gettimeofday(&tend, NULL);
  timer = tend.tv_sec - tstart.tv_sec + (tend.tv_usec - tstart.tv_usec)/1.e6;
  int timestamp = time(0);
  printf("Computed mandelbrot set (size=%dx%d) in %f seconds\n", size, size, timer);

  // write ppm
  char filename[256];
  sprintf(filename, "multi-mandelbrot_%d_%d.ppm", size, timestamp);
  write_ppm(filename, shm_pixels, size, size);
  free(pallet);
  
  return 0;
  
  // compute image
}
