cmake_minimum_required(VERSION 3.30.2)

project(AnsibleScriptRunner CXX)

file(GLOB_RECURSE HEADERS CONFIGURE_DEPENDS "${PROJECT_SOURCE_DIR}/include/**.h")
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "${PROJECT_SOURCE_DIR}/src/input/**.cpp")

source_group(TREE ${PROJECT_SOURCE_DIR} FILES ${SOURCES} ${HEADERS})

add_executable(asu ${SOURCES})

target_compile_features(asu PRIVATE cxx_std_23)
target_include_directories(asu PRIVATE include)

target_sources(asu
	PRIVATE
		${SOURCES}
)