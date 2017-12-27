cmake_minimum_required (VERSION 3.8)

project (example)

#set(CODE_SIGN_ID "Developer ID Application: Your Name. (XYZZYYZYZY)")
#set(CMAKE_OSX_SYSROOT /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.11.sdk/)


if(CMAKE_BUILD_TYPE MATCHES Debug)
	add_definitions(-DDEBUG)
endif()

add_definitions(
	-DKERNEL
	-DKERNEL_PRIVATE
	-DDRIVER_PRIVATE
	-DAPPLE
	-DNeXT
)

include_directories(
	${CMAKE_OSX_SYSROOT}/System/Library/Frameworks/Kernel.framework/PrivateHeaders
	${CMAKE_OSX_SYSROOT}/System/Library/Frameworks/Kernel.framework/Headers
)

add_executable(
	${PROJECT_NAME}
	MACOSX_BUNDLE
	src/example.c
	src/example_info.c
	src/Info.plist
)

set_target_properties(${PROJECT_NAME} PROPERTIES BUNDLE_EXTENSION kext MACOSX_BUNDLE_INFO_PLIST ${PROJECT_SOURCE_DIR}/src/Info.plist)


add_compile_options(${PROJECT_NAME}
	-x c -arch x86_64 -fmessage-length=0
	-fdiagnostics-show-note-include-stack
	-fmacro-backtrace-limit=0 -nostdinc
	-std=gnu99 -fmodules -gmodules
	-Wnon-modular-include-in-framework-module
	-Werror=non-modular-include-in-framework-module
	-fno-builtin -Wno-trigraphs -msoft-float -O0 -fno-common
	-mkernel -Wno-missing-field-initializers -Wno-missing-prototypes
	-Werror=return-type -Wdocumentation -Wunreachable-code
	-Werror=deprecated-objc-isa-usage -Werror=objc-root-class
	-Wno-missing-braces -Wparentheses -Wswitch -Wunused-function
	-Wno-unused-label -Wno-unused-parameter -Wunused-variable -Wunused-value
	-Wempty-body -Wconditional-uninitialized -Wno-unknown-pragmas
	-Wno-shadow -Wno-four-char-constants -Wno-conversion -Wconstant-conversion
	-Wint-conversion -Wbool-conversion -Wenum-conversion -Wshorten-64-to-32
	-Wpointer-sign -Wno-newline-eof
	-fasm-blocks -fstrict-aliasing -Wdeprecated-declarations
	-mmacosx-version-min=10.10 -Wno-sign-conversion
	-Winfinite-recursion -iquote
)

target_link_libraries(${PROJECT_NAME} 
	"-lkmodc++"
	"-lkmod"
	"-lcc_kext"
	"-arch x86_64"
	"-mmacosx-version-min=10.11"
	"-nostdlib"
	"-Xlinker -object_path_lto"
	"-Xlinker -export_dynamic"
	"-Xlinker -kext"
)

#add_custom_command (TARGET ${PROJECT_NAME} POST_BUILD
#	COMMENT "Signing With ID: ${CODE_SIGN_ID}"
#	VERBATIM
#	COMMAND
#	/usr/bin/codesign -s "${CODE_SIGN_ID}" "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}.kext"
#)

