#include <stdio.h>
#include "timer.h"
#include "lily58_x.h"

char timelog_str[24] = {};
int last_time = 0;
uint32_t elapsed_time = 0;

void set_timelog(void) {
  elapsed_time = timer_elapsed32(last_time);
  int d = elapsed_time/1000/60/60/24;
  int h = elapsed_time/1000/60/60%24;
  int m = elapsed_time/1000/60%60;
  int s = elapsed_time/1000%60;
  snprintf(timelog_str, sizeof(timelog_str), "%ddays %02d:%02d:%02d",d,h,m,s);
}

const char *read_timelog(void) {
  return timelog_str;
}
