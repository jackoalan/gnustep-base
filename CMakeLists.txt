cmake_minimum_required(VERSION 2.8)


# Dev tool directories
set(WS_LLVM_BIN_DIR ${WiiStep_BINARY_DIR}/llvm/bin)
set(WS_DKPPC_BIN_DIR ${WiiStep_BINARY_DIR}/devkitPPC/bin)

# PPC include/lib directories
set(WS_PPC_INCLUDE_DIRS ${WiiStep_BINARY_DIR}/devkitPPC/powerpc-eabi/include;${WiiStep_BINARY_DIR}/libogc/include;${WiiStep_SOURCE_DIR}/gnustep-libobjc2)
set(WS_PPC_LIB_DIRS ${WiiStep_BINARY_DIR}/devkitPPC/powerpc-eabi/lib;${WiiStep_BINARY_DIR}/libogc/lib/wii)

# Objective-C runtime built files
set(WS_PPC_OBJC_LLVM ${WiiStep_BINARY_DIR}/libobjc-wii.bc)
set(WS_PPC_OBJC_ELF ${WiiStep_BINARY_DIR}/libobjc-wii-asm.a)

# Compile support files
set(WS_PPC_PCH ${WiiStep_SOURCE_DIR}/wii-prefix.pch)
set(WS_PPC_SUPPORT_C "-I${WiiStep_BINARY_DIR}/libogc/include ${WiiStep_SOURCE_DIR}/wii-support.c")

# Include WiiStep CMake macros
include(${WiiStep_SOURCE_DIR}/cmake/WiiStepProjectMacros.cmake)

include_directories(Headers)
add_subdirectory(Source)

file(GLOB GS_FOUNDATION_HEADERS Headers/Foundation/*.h)
install(FILES ${GS_FOUNDATION_HEADERS} DESTINATION "${INSTALL_WS_DIR}/${PPC_WII_DIR}/include/Foundation")
file(GLOB GS_BASE_HEADERS Headers/GNUstepBase/*.h)
install(FILES ${GS_BASE_HEADERS} DESTINATION "${INSTALL_WS_DIR}/${PPC_WII_DIR}/include/GNUstepBase")
install(FILES Headers/config.h DESTINATION "${INSTALL_WS_DIR}/${PPC_WII_DIR}/include/GNUstepBase")

