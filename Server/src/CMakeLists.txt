qt_add_executable(${PROJECT_NAME}
    App/CConnectionThread.cpp
    App/CConnectionThread.h
    App/CServer.cpp
    App/CServer.h

    UI/CMainWindow.ui
    UI/CMainWindow.cpp
    UI/CMainWindow.h

    PostgreSQL/IConnector.h
    PostgreSQL/CDataBaseConnector.h
    PostgreSQL/CDataBaseConnector.cpp

    main.cpp
)

target_include_directories(${PROJECT_NAME} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR} PRIVATE ${LIBPQXX_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Widgets Qt6::Network ${PQXX_LINK_LIBRARIES} PostgreSQL::PostgreSQL)

set_target_properties(${PROJECT_NAME} PROPERTIES
    WIN32_EXECUTABLE ON
    MACOSX_BUNDLE ON
)