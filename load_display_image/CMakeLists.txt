cmake_minimum_required( VERSION 2.8 )
project ( load_display_image )
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )
add_executable( load_display_image load_display_image.cpp )
target_link_libraries( load_display_image ${OpenCV_LIBS} )