cmake_minimum_required(VERSION 3.0.0)
project(Sudoku VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)
include(CTest)
enable_testing()
add_definitions(
		"-Wall"
		"-Wextra"
) 
add_executable(
    Sudoku
    aid/draw.cpp
    aid/copypaste.cpp
    aid/stringboard.cpp
    aid/get_key.cpp
    generate/generate_lib.cpp
    generate/generate_saves.cpp
    generate/generate_cp.cpp
    generate/generate_menu.cpp
    play/game_board.cpp
    play/game_aid.cpp
    play/operation/move.cpp
    play/operation/write_number.cpp
    play/operation/regame.cpp
    play/operation/undo_redo.cpp
    play/operation/solve.cpp
    play/operation/complete_game.cpp
    play/operation/copy_to_paste.cpp
    play/operation/save_game.cpp
    play/print/print_board.cpp
    play/print/print_hint.cpp
    play/print/print_message.cpp
    play/run_game.cpp
    setting/setting_menu.cpp
    setting/difficulty.cpp
    setting/open_hint.cpp
    setting/setting_file.cpp
    setting/key_board_menu.cpp
    setting/key_board.cpp
    start.cpp
    main.cpp
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
