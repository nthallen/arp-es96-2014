/* SWData.h */
#ifndef SWDATA_H_INCLUDED
#define SWDATA_H_INCLUDED

typedef struct __attribute__((__packed__)) {
  unsigned char SWStat;
} SWData_t;
extern SWData_t SWData;

#define SWS_SCRUB_START 1
#define SWS_SCRUB_STOP 2
#define SWS_RECORD 3
#define SWS_SHUTDOWN 255

#endif
