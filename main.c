#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <libnotify/notify.h>

int secondsSince(struct timespec *start) {
  // return antal sekunder sedan 'start'
  struct timespec now;
  clock_gettime(CLOCK_MONOTONIC, &now);
  int seconds = now.tv_sec - start->tv_sec;
  return seconds;
}

int main(int argc, char *argv[]) {
  // default delay
  int delay = 5;

  // eller angiven delay
  if (argc > 1) {
    delay = atoi(argv[1]);
  }

  struct timespec start;
  clock_gettime(CLOCK_MONOTONIC, &start);

  notify_init("TeaC");
  NotifyNotification * timerSet = notify_notification_new ("TeaC", "Someone set us up the timer", NULL);
  notify_notification_show (timerSet, NULL);
  g_object_unref(G_OBJECT(timerSet));
  
  NotifyNotification * timerDone = notify_notification_new ("Your tea is done!", "All your tea are belong to us", NULL);

  while (secondsSince(&start) < delay) {
    
  }
  printf("%d second(s) has passed. Have a nice day. \n", delay);
  notify_notification_show(timerDone, NULL);
  g_object_unref(G_OBJECT(timerDone));
  notify_uninit();
}
