cmake_minimum_required(VERSION 3.16)
project(abworld)

set(CMAKE_CXX_STANDARD 14)
#add_custom_target(ab)
find_package( ZLIB REQUIRED )
if ( ZLIB_FOUND )
    include_directories( ${ZLIB_INCLUDE_DIRS} )
#    add_subdirectory(../../../LIB/ZLIB/Lib ${CMAKE_BINARY_DIR}/ZLIB)
    link_libraries(${ZLIB_LIBRARIES} )
#    target_link_libraries( ab ${ZLIB_LIBRARIES} )
endif( ZLIB_FOUND )
add_executable(abworld main.cpp TBufEC.cpp TBufEC.h windows.h OKGF.cpp OKGF.h TabWorldUnit.cpp TabWorldUnit.h TabObj3D.cpp TabObj3D.h TabTex.cpp TabTex.h TabObj3Dunit.cpp TabObj3Dunit.h WorldUnit.cpp WorldUnit.h ABKey.cpp ABKey.h TKeyGroupList.cpp TKeyGroupList.h ABPoint.cpp ABPoint.h TPointAB.cpp TPointAB.h Utils.cpp Utils.h ABTriangle.cpp ABTriangle.h TTriangleAB.cpp TTriangleAB.h TKeyAB.cpp TKeyAB.h ABLine.cpp ABLine.h TLineAB.cpp TLineAB.h WorldZone.cpp WorldZone.h TabZone.cpp TabZone.h TabZoneLink.cpp TabZoneLink.h)

