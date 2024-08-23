qt_add_executable(${PROJECT_NAME}
    main.cpp

    #UI/CMainWindow.ui
    UI/CMainWindow.cpp
    UI/CMainWindow.h

    UI/Components/Widgets/CCustomShadowEffect.cpp
    UI/Components/Widgets/CCustomShadowEffect.h

    UI/Components/Widgets/CInputText.cpp
    UI/Components/Widgets/CInputText.h

    App/CConnection.cpp
    App/CConnection.h
)

target_include_directories(${PROJECT_NAME} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Widgets Qt6::Network pthread)

set_target_properties(${PROJECT_NAME} PROPERTIES
    WIN32_EXECUTABLE ON
    MACOSX_BUNDLE ON
)
