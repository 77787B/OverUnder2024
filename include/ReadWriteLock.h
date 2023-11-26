#ifndef READWRITELOCK_H_
#define READWRITELOCK_H_

#include "vex.h"
#include "mutex"

class readWriteLock {
  private:
    mutex readMtx;
    mutex writeMtx;
    int readCnt; // 已加读锁个数

  public:
    readWriteLock() : readCnt(0) {}
    void readLock();
    void readUnlock();
    void writeLock();
    void writeUnlock();
};

#endif