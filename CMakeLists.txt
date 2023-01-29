cmake_minimum_required(VERSION 3.24)
project(minesweeper_qt)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_PREFIX_PATH "/usr/local/Cellar/qt@5/5.15.7/lib/cmake")

find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Quick REQUIRED)

set(INFO src/appinfo.h)
set(BOARD src/gameboard.cpp src/gameboard.h)
set(SCORE src/highScore.cpp src/highScore.h
        src/highScoreDialog.cpp src/highScoreDialog.h
        src/highScoreModel.cpp src/highScoreModel.h)
set(COUNTER src/mineCounter.cpp src/mineCounter.h)
set(TIMER src/minetimer.cpp src/minetimer.h)
set(TILE src/tile.cpp src/tile.h)
set(RESOURCE resources/resources.qrc resources/resources.rc)
set(MAINWINDOW src/main.cpp src/mainwindow.cpp src/mainwindow.h)

add_executable(${PROJECT_NAME} ${MAINWINDOW} ${BOARD} ${SCORE} ${COUNTER} ${TIMER} ${INFO} ${TILE} ${RESOURCE})

target_link_libraries(minesweeper_qt Qt5::Core)
target_link_libraries(minesweeper_qt Qt5::Widgets)
target_link_libraries(minesweeper_qt Qt5::Quick)