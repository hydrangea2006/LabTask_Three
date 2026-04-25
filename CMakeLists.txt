cmake_minimum_required(VERSION 3.16)

project(LabTask_Three VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(LabTask_Three
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        palindromepage.h palindromepage.cpp palindromepage.ui
        palindrome_logic.h palindrome_logic.cpp
        windchill_logic.h windchill_logic.cpp
        WindchillPage.h WindchillPage.cpp WindchillPage.ui
        coffeeshop_logic.h coffeeshop_logic.cpp
        coffeeshoppage.h coffeeshoppage.cpp coffeeshoppage.ui
        gravity_logic.h gravity_logic.cpp
        gravitypage.h gravitypage.cpp gravitypage.ui
        circlecal_logic.h circlecal_logic.cpp
        circlecalpage.h circlecalpage.cpp circlecalpage.ui
        taylorpage.h taylorpage.cpp taylorpage.ui
        taylor_logic.h taylor_logic.cpp
        recursiveexponent.h recursiveexponent.cpp recursiveexponent.ui
        power_logic.h power_logic.cpp
        cointosspage.h cointosspage.cpp cointosspage.ui
        cointoss_logic.cpp
        cointoss_logic.h cointoss_logic.cpp

    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET LabTask_Three APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(LabTask_Three SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(LabTask_Three
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(LabTask_Three PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.LabTask_Three)
endif()
set_target_properties(LabTask_Three PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS LabTask_Three
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(LabTask_Three)
endif()
