cmake_minimum_required(VERSION 2.8)
project(foundation-wii)

include_directories(.)

add_wii_library(foundation-wii
  NSObjCRuntime.m Additions/GSObjcRuntime.m 
  externs.m
  NSObject.m
  NSAutoreleasePool.m
  NSValue.m
  NSNumber.m
  NSDecimal.m
  NSScanner.m
  GSArray.m NSArray.m
  GSDictionary.m NSDictionary.m
  GSString.m NSString.m
  NSData.m
  NSDate.m
  NSMapTable.m NSConcreteMapTable.m
  NSHashTable.m NSConcreteHashTable.m
  NSPointerArray.m
  NSPointerFunctions.m NSConcretePointerFunctions.m
  NSZone.m
  NSException.m
  NSError.m
  NSLog.m
  NSDebug.m
  NSLock.m Additions/NSLock+GNUstepBase.m Additions/GSLock.m
  Additions/Unicode.m
  NSProcessInfo.m Additions/NSProcessInfo+GNUstepBase.m
  Additions/NSDebug+GNUstepBase.m
  NSSortDescriptor.m
  NSPropertyList.m
  NSFileManager.m
  NSCallbacks.m
  NSRange.m
  #NSUserDefaults.m
  GSPrivateHash.m
  NSThread.m
  NSPage.m
  NSCopyObject.m
  GSFormat.m
  NSCalendarDate.m
  GSLocale.m
  #NSPathUtilities.m
  NSRunLoop.m
  NSNotificationQueue.m
  GSTimSort.m
  NSTimer.m
  unix/GSRunLoopCtxt.m
  GSRunLoopWatcher.m)

add_definitions(
-D GNUSTEP_BASE_INTERNAL
-fno-objc-arc)

install(TARGETS foundation-wii
  EXPORT WiiStepTargets
  ARCHIVE DESTINATION "${INSTALL_WS_DIR}/${PPC_WII_DIR}/lib"
  COMPONENT dev)

