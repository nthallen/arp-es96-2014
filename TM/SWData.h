/* SWData.h */
#ifndef SWDATA_H_INCLUDED
#define SWDATA_H_INCLUDED

typedef struct __attribute__((__packed__)) {
  unsigned char SWStat;
  unsigned char AlgoP1;
  unsigned char AlgoP2;
  unsigned char AlgoP3;
  unsigned char AlgoP4;
} SWData_t;
extern SWData_t SWData;

#define SWS_SCRUB_START 1
#define SWS_SCRUB_STOP 2
#define SWS_RECORD 3
#define SWS_FLASH_HEAT_ON 20
#define SWS_FLASH_HEAT_OFF 21
#define SWS_FLASH_HEAT_DONE 22
#define SWS_OFF_GROUND 30
#define SWS_STRATOSPHERE 31
#define SWS_TERMINATE 32
#define SWS_TIME_WARP 254
#define SWS_SHUTDOWN 255

#endif
