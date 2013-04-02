cmake_minimum_required(VERSION 2.8)
project(foundation-wii)

include_directories(.)

add_wii_library(foundation-wii
  NSObjCRuntime.m Additions/GSObjcRuntime.m 
  NSObject.m
  NSValue.m
  NSNumber.m
  GSArray.m NSArray.m
  GSDictionary.m NSDictionary.m
  GSString.m NSString.m
  NSData.m
  NSMapTable.m NSConcreteMapTable.m
  NSHashTable.m NSConcreteHashTable.m
  NSPointerArray.m
  NSPointerFunctions.m NSConcretePointerFunctions.m
  NSZone.m
  NSException.m
  NSError.m
  NSLog.m
  NSDebug.m
  Additions/GSLock.m
  Additions/Unicode.m
  NSProcessInfo.m Additions/NSProcessInfo+GNUstepBase.m
  Additions/NSDebug+GNUstepBase.m)

add_definitions(
-D GNUSTEP_BASE_INTERNAL)
