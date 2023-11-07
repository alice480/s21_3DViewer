# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "3DViewer_autogen"
  "CMakeFiles/3DViewer_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/3DViewer_autogen.dir/ParseCache.txt"
  "QtGifImage/src/3rdParty/CMakeFiles/giflib_autogen.dir/AutogenUsed.txt"
  "QtGifImage/src/3rdParty/CMakeFiles/giflib_autogen.dir/ParseCache.txt"
  "QtGifImage/src/3rdParty/giflib_autogen"
  "QtGifImage/src/CMakeFiles/QtGifImage_autogen.dir/AutogenUsed.txt"
  "QtGifImage/src/CMakeFiles/QtGifImage_autogen.dir/ParseCache.txt"
  "QtGifImage/src/QtGifImage_autogen"
  "backend/CMakeFiles/backend_autogen.dir/AutogenUsed.txt"
  "backend/CMakeFiles/backend_autogen.dir/ParseCache.txt"
  "backend/backend_autogen"
  )
endif()
