cmake_minimum_required(VERSION 2.8)
project(foundation-wii)

add_wii_library(foundation-wii 
  NSObject.m
  GSArray.m NSArray.m
  GSDictionary.m NSDictionary.m
  GSString.m NSString.m
  NSData.m
  NSMapTable.m
  NSHashTable.m
  NSPointerArray.m)

add_definitions(
-D GNUSTEP_BASE_INTERNAL)
