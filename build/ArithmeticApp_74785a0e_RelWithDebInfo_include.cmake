if(EXISTS "D:/егэ информатика/lab3/build/RelWithDebInfo/ArithmeticApp.exe")
  discover_tests(
    COMMAND "C:/Program Files/CMake/bin/cmake.exe"
      -D [[TEST_EXECUTABLE=D:/егэ информатика/lab3/build/RelWithDebInfo/ArithmeticApp.exe]]
      -D [[TEST_EXECUTOR=]]
    DISCOVERY_ARGS
      -D [[TEST_FILTER=]]
      -D [[TEST_DISCOVERY_EXTRA_ARGS=]]
      -D [[NO_PRETTY_TYPES=FALSE]]
      -D [[NO_PRETTY_VALUES=FALSE]]
      -P [[C:/Program Files/CMake/share/cmake-4.4/Modules/GoogleTest/DiscoverTests.cmake]]
    DISCOVERY_MATCH
      "-- ([^#]+)#([^#]+)#DISABLED=([^#]+)#LOCATION=([^#]*)#"
    DISCOVERY_PROPERTIES
      TIMEOUT [[5]]
      WORKING_DIRECTORY [[D:/егэ информатика/lab3/build]]
    TEST_NAME [[\1]]
    TEST_ARGS
      -D [[TEST_FILTER=\2]]
      -D [[TEST_XML_OUTPUT=]]
      -D [[TEST_EXTRA_ARGS=]]
      -P [[C:/Program Files/CMake/share/cmake-4.4/Modules/GoogleTest/LaunchTest.cmake]]
    TEST_PROPERTIES
      DISABLED [[\3]]
      DEF_SOURCE_LINE [[\4]]
      SKIP_REGULAR_EXPRESSION "\\[  SKIPPED \\]"
      WORKING_DIRECTORY [[D:/егэ информатика/lab3/build]]
      
    TEST_LIST ArithmeticApp_TESTS
  )
  list(TRANSFORM ArithmeticApp_TESTS REPLACE ";" "\n")
  list(FILTER ArithmeticApp_TESTS EXCLUDE REGEX "(\\[|])")
  list(TRANSFORM ArithmeticApp_TESTS REPLACE "\n" [[\\;]])
else()
  add_test(ArithmeticApp_NOT_BUILT ArithmeticApp_NOT_BUILT)
endif()
