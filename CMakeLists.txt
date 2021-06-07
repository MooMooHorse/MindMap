cmake_minimum_required(VERSION 3.5)

project(mindmap)


add_library(mindmaplib STATIC 
"libgraphics/exceptio.c"
"libgraphics/genlib.c"
"libgraphics/graphics.c"
"libgraphics/linkedlist.c"
"libgraphics/random.c"
"libgraphics/simpio.c"
"libgraphics/strlib.c"
"simpleGUI/imgui.c"
"mindmap/ButtonRelated.c"
"mindmap/Line.c"
"mindmap/TextBox.c"
"mindmap/Display.c"
"mindmap/Output.c"
"simpleGUI/mygui.c"
)

target_include_directories(mindmaplib
    PUBLIC
        "${PROJECT_SOURCE_DIR}/lib"
)
add_executable(mindmap
    "mindmap/Main.c"
)
target_link_libraries( mindmap
    PRIVATE
        mindmaplib
)