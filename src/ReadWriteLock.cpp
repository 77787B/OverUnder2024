#include "ReadWriteLock.h"

void readWriteLock::readLock(){
  readMtx.lock();
  if (++readCnt == 1) {
    writeMtx.lock();  // 存在线程读操作时，写加锁（只加一次）
  }
  readMtx.unlock();
}

void readWriteLock::readUnlock(){
  readMtx.lock();
  if (--readCnt == 0) { // 没有线程读操作时，释放写锁
    writeMtx.unlock();
  }
  readMtx.unlock();
}

void readWriteLock::writeLock(){
  writeMtx.lock();
}

void readWriteLock::writeUnlock() {
  writeMtx.unlock();
}