project (jderobot)

cmake_minimum_required(VERSION 2.8)


#check compiller
if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
	include(CheckCXXCompilerFlag)
	CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
	CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)
	message (version: ${CMAKE_CXX_COMPILER_VERSION})
	if(COMPILER_SUPPORTS_CXX11)
    	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
	elseif(COMPILER_SUPPORTS_CXX0X)
        #boost have problems with gcc < 4.7 and c++0x
        if(CMAKE_CXX_COMPILER_VERSION VERSION_GREATER "4.7.0")
    		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
        endif()
	else()
		    message(STATUS "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support.")
	endif()

endif()

# ENV VARS
SET(gladedir ./)
SET( DEPS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/Deps) # Directory where the dependencies are there
# Folder with ROS Header files
SET( ROS_HEADER_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src/stable/libs/RosLib/include/RosLib)
# Folder with ICE cpp interfaces
SET( INTERFACES_CPP_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src/stable/interfaces/cpp/jderobot ${CMAKE_CURRENT_SOURCE_DIR}/src/stable/interfaces/cpp/)
# Folder with ICE python interfaces
SET( INTERFACES_PYTHON_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src/stable/interfaces/python/jderobot ${CMAKE_CURRENT_SOURCE_DIR}/src/stable/interfaces/python/)
# Folder with ICE java interfaces
SET( INTERFACES_JAVA_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src/stable/interfaces/java/jderobot ${CMAKE_CURRENT_SOURCE_DIR}/src/stable/interfaces/java/)
# Folder JdeRobot libraries 
SET( LIBS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src/stable/libs) 
# Folder ICE interface definitions
SET( SLICE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src/stable/interfaces/slice)
# Main libraries
SET( LIBS_NEEDED  colorspaces jderobotutil progeo pioneer fuzzylib visionlib parallelIce )

# Create directories if necessary
file(MAKE_DIRECTORY ${INTERFACES_PYTHON_DIR})
file(MAKE_DIRECTORY ${INTERFACES_JAVA_DIR})

# MACRO to get the list of subdirectories
macro(list_subdirectories retval curdir return_relative)
  file(GLOB sub-dir RELATIVE ${curdir} *)
  set(list_of_dirs "")
  foreach(dir ${sub-dir})
    if(IS_DIRECTORY ${curdir}/${dir})
      if (${return_relative})
        if (NOT ${dir} MATCHES "CMakeFiles" AND NOT ${dir} MATCHES ".svn")
                set(list_of_dirs ${list_of_dirs} ${dir})
        endif()
      else()
        set(list_of_dirs ${list_of_dirs} ${curdir}/${dir})
      endif()
    endif()
  endforeach()
  set(${retval} ${list_of_dirs})
endmacro()

# MACRO to get the list subdir of other path distinct to current path
macro(list_subdirectories2 retval curdir return_relative)
  file(GLOB sub-dir RELATIVE ${curdir} ${curdir}*)
  set(list_of_dirs "")
  foreach(dir ${sub-dir})
    if(IS_DIRECTORY ${curdir}/${dir})
      if (${return_relative})        
        if (NOT ${dir} MATCHES "CMakeFiles" AND NOT ${dir} MATCHES ".svn")
                set(list_of_dirs ${list_of_dirs} ${dir})
        endif()
      else()
        set(list_of_dirs ${list_of_dirs} ${curdir}/${dir})
      endif()
    endif()
  endforeach()
  set(${retval} ${list_of_dirs})
endmacro()




###################
#                 #
#  CHECK SYSTEM   #
#                 #
###################

  # FIND & CHECK PRINCIPAL LIBRARIES

include(FindPkgConfig)

PKG_CHECK_MODULES(gsl REQUIRED gsl)
include_directories(${gsl_INCLUDE_DIRS})
link_directories(${gsl_LIBRARIES_DIRS})

PKG_CHECK_MODULES(eigen REQUIRED eigen3)
include_directories(${eigen_INCLUDE_DIRS})


link_directories(${INTERFACES_CPP_DIR}/jderobot)
FOREACH(LibFile ${LIBS_NEEDED})
    link_directories(${LIBS_DIR}/${LibFile})
    MESSAGE("${LIBS_DIR}/${LibFile}")
ENDFOREACH(LibFile)

  # FIND AND CHECK OTHER DEPENDENCES

include(${DEPS_DIR}/gazebo/CMakeLists.txt)
include(${DEPS_DIR}/fireware/CMakeLists.txt)
include(${DEPS_DIR}/pcl/CMakeLists.txt)
include(${DEPS_DIR}/openni/CMakeLists.txt)
include(${DEPS_DIR}/nite/CMakeLists.txt)
include(${DEPS_DIR}/xerces/CMakeLists.txt)
include(${DEPS_DIR}/ice/CMakeLists.txt)
include(${DEPS_DIR}/cwiid/CMakeLists.txt)
include(${DEPS_DIR}/opencv/CMakeLists.txt)
include(${DEPS_DIR}/opengl/CMakeLists.txt)
include(${DEPS_DIR}/openni2/CMakeLists.txt)
include(${DEPS_DIR}/nite2/CMakeLists.txt)
include(${DEPS_DIR}/pthread/CMakeLists.txt)
include(${DEPS_DIR}/libxml++/CMakeLists.txt)
include(${DEPS_DIR}/libxml2/CMakeLists.txt)
include(${DEPS_DIR}/boost/CMakeLists.txt)
include(${DEPS_DIR}/alut/CMakeLists.txt)
include(${DEPS_DIR}/tinyxml/CMakeLists.txt)
include(${DEPS_DIR}/gtk2/CMakeLists.txt)
include(${DEPS_DIR}/qt/CMakeLists.txt)
include(${DEPS_DIR}/gtk3/CMakeLists.txt)
include(${DEPS_DIR}/kobuki/CMakeLists.txt)
include(${DEPS_DIR}/libusb/CMakeLists.txt)
include(${DEPS_DIR}/zlib/CMakeLists.txt)
include(${DEPS_DIR}/openssl/CMakeLists.txt)
include(${DEPS_DIR}/libfreenect2/CMakeLists.txt)
include(${DEPS_DIR}/ogre/CMakeLists.txt)
include(${DEPS_DIR}/findPythonModules/CMakeLists.txt)
include(${DEPS_DIR}/opencv_py/CMakeLists.txt)
include(${DEPS_DIR}/ice_py/CMakeLists.txt)
include(${DEPS_DIR}/numpy/CMakeLists.txt)
include(${DEPS_DIR}/pyqt4/CMakeLists.txt)
include(${DEPS_DIR}/qwt5_py/CMakeLists.txt)
include(${DEPS_DIR}/matplotlib_py/CMakeLists.txt)
include(${DEPS_DIR}/qwt5/CMakeLists.txt)
include(${DEPS_DIR}/cuda/CMakeLists.txt)


#include(${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/CMakeLists.txt)



#file(READ ${CMAKE_CURRENT_SOURCE_DIR}/jderobot.cfg contents)

# START RECURSIVE
add_subdirectory (${CMAKE_CURRENT_SOURCE_DIR}/src)



###################
#                 #
#    INSTALL      #
#                 #
###################

INSTALL(FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/stable/interfaces/libJderobotInterfaces.so DESTINATION /usr/local/lib/jderobot)

# Install python files
FILE(GLOB_RECURSE HEADERS_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/stable/interfaces/python/jderobot/*py)
FOREACH(header ${HEADERS_FILES})
	INSTALL(FILES ${header} DESTINATION /usr/lib/python2.7/jderobot/)
ENDFOREACH(header)

INSTALL(FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/stable/interfaces/python/jderobot/jderobot/__init__.py DESTINATION /usr/lib/python2.7/jderobot/)

# install all libraries 
FILE(GLOB LIB_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/stable/libs/*/*.so*)
FOREACH (lib ${LIB_FILES})
	INSTALL (FILES ${lib} DESTINATION /usr/local/lib/jderobot)
ENDFOREACH(lib)

FILE(GLOB LIB_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/stable/libs/visionlib/*/*.so*)
FOREACH (lib ${LIB_FILES})
	INSTALL (FILES ${lib} DESTINATION /usr/local/lib/jderobot)
ENDFOREACH(lib)


FILE(GLOB_RECURSE HEADERS_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/stable/libs/*.h)
FOREACH(currentSourceFile ${HEADERS_FILES})
    string(REGEX REPLACE "(.*/).*.h" "\\1" new_source1 ${currentSourceFile})
		string(REGEX REPLACE  "${CMAKE_CURRENT_SOURCE_DIR}/src/stable/libs" "" new_source2 ${new_source1})
    INSTALL (FILES ${currentSourceFile} DESTINATION /usr/local/include/jderobot/${new_source2})
ENDFOREACH(currentSourceFile)

# Install libraries headers
FILE(GLOB_RECURSE HEADERS_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/stable/libs/*.h)
FOREACH(currentSourceFile ${HEADERS_FILES})
	string(REGEX REPLACE ".*/(.*/).*.h" "\\1" new_source1 ${currentSourceFile})
	INSTALL (FILES ${currentSourceFile} DESTINATION /usr/local/include/jderobot/${new_source1})
ENDFOREACH(currentSourceFile)

# Install Executables
list_subdirectories2( LIST_COMPONENTS ${CMAKE_CURRENT_SOURCE_DIR}/src/stable/components/ 1)

FOREACH (currentBin ${LIST_COMPONENTS})
    #SET(EXIST EXIST-NOTFOUND)
    find_file(EXIST NAMES ${currentBin} PATHS ${CMAKE_CURRENT_SOURCE_DIR}/src/components/${currentBin})
    #IF (EXIST)
    INSTALL (FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/stable/components/${currentBin}/${currentBin} DESTINATION /usr/local/bin OPTIONAL PERMISSIONS OWNER_EXECUTE GROUP_EXECUTE WORLD_EXECUTE)
    #ENDIF(EXIST)
    #MESSAGE("${EXIST}")
ENDFOREACH(currentBin)

# Install interfaces headers
FILE(GLOB HEADER_INTERFACE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/stable/interfaces/cpp/jderobot/*.h)
INSTALL (FILES ${HEADER_INTERFACE_FILES} DESTINATION /usr/local/include/jderobot)

# Install slice
FILE(GLOB SLICE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/stable/interfaces/slice/jderobot/*.ice)
INSTALL (FILES ${SLICE_FILES} DESTINATION /usr/local/include/jderobot/slice)

# Install CONF
FILE(GLOB_RECURSE CONF_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/stable/components/*.cfg)
INSTALL (FILES ${CONF_FILES} DESTINATION /usr/local/share/jderobot/conf)

# Install Glade
FILE(GLOB_RECURSE GLADE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/stable/components/*.glade)
INSTALL (FILES ${GLADE_FILES} DESTINATION /usr/local/share/jderobot/glade)



###################
#                 #
#    UNINSTALL    #
#                 #
###################

configure_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/cmake_uninstall.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake"
    IMMEDIATE @ONLY)

add_custom_target(uninstall
    COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake)

#
# Deb packages
#

# Determine current architecture
macro(dpkg_arch VAR_NAME)
        find_program(DPKG_PROGRAM dpkg DOC "dpkg program of Debian-based systems")
        if (DPKG_PROGRAM) 
          execute_process(
            COMMAND ${DPKG_PROGRAM} --print-architecture
            OUTPUT_VARIABLE ${VAR_NAME}
            OUTPUT_STRIP_TRAILING_WHITESPACE
          )
        endif(DPKG_PROGRAM)
endmacro(dpkg_arch)

include (InstallRequiredSystemLibraries)
SET (CPACK_GENERATOR "DEB")
SET (CPACK_SOURCE_GENERATOR TGZ)
SET (CPACK_DEBIAN_PACKAGE_SHLIBDEPS ON)
SET (CPACK_SET_DESTDIR "on")
SET (CPACK_PACKAGING_INSTALL_PREFIX "/usr/local")


SET (VERSION 5.3.0-rc1)
# CPack version numbers for release tarball name.
SET (CPACK_PACKAGE_VERSION_MAJOR 5)
SET (CPACK_PACKAGE_VERSION_MINOR 3)
SET (CPACK_PACKAGE_VERSION_PATCH 0)
SET (CPACK_DEBIAN_PACKAGE_VERSION ${VERSION})


SET (CPACK_DEBIAN_PACKAGE_PRIORITY "extra")
SET (CPACK_DEBIAN_PACKAGE_SECTION "net")
dpkg_arch(CPACK_DEBIAN_PACKAGE_ARCHITECTURE)

#MESSAGE("Dependencias: ${DEPS}")

SET(CPACK_DEBIAN_PACKAGE_DEPENDS "${DEPS}")

set(CPACK_DEBIAN_PACKAGE_CONTROL_EXTRA
    "${CMAKE_CURRENT_SOURCE_DIR}/scripts/cmake/postinst"
    "${CMAKE_CURRENT_SOURCE_DIR}/scripts/cmake/postrm")

SET (CPACK_PACKAGE_DESCRIPTION_SUMMARY "JdeRobot is a software development suite for robotics applications.")
SET (CPACK_PACKAGE_DESCRIPTION "JdeRobot is a software development suite for robotics applications, written in C++ language. It provides a programming environment where the robot control program is made up of a collection of several concurrent asynchronous threads named schemas. It is based on JDE cognitive architecture for autonomous robots.")

SET (CPACK_PACKAGE_CONTACT "Roberto Calvo <rocapal@gsyc.urjc.es>")
SET (CPACK_PACKAGE_FILE_NAME "${CMAKE_PROJECT_NAME}_${VERSION}_${CPACK_DEBIAN_PACKAGE_ARCHITECTURE}")

SET (CPACK_COMPONENTS_ALL Libraries ApplicationData)
include (CPack Documentation)
