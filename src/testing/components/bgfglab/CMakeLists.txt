SET( gladedir ${CMAKE_CURRENT_SOURCE_DIR})

SET( SOURCE_FILES controller.cpp main.cpp mainthread.cpp model.cpp viewgtk.cpp viewtext.cpp )


add_definitions(-DGLADE_DIR="${gladedir}")


include_directories(
    ${INTERFACES_CPP_DIR}
    ${LIBS_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR})

add_executable (bgfglab ${SOURCE_FILES})

TARGET_LINK_LIBRARIES( bgfglab
    ${opencv_LIBRARIES}
    ${gtkmm_LIBRARIES}
    ${libglademm_LIBRARIES}
	  ${GLUT_LIBRARIES}
    ${OpenCV_LIBRARIES}
    ${LIBS_DIR}/jderobotice/libjderobotice.so
    ${LIBS_DIR}/jderobotutil/libjderobotutil.so
    ${LIBS_DIR}/colorspaces/libcolorspacesmm.so
    ${INTERFACES_CPP_DIR}/jderobot/libJderobotInterfaces.so
    ${LIBS_DIR}/bgfgsegmentation/libbgfgsegmentation.so
    ${Gearbox_LIBRARIES}
    ${ZeroCIce_LIBRARIES}
    )
