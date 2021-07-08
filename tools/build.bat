@echo off

:: Build the project
cmake . -BBUILD
cmake --build BUILD --config Release

:: Copy built binary to dist folder
IF NOT EXIST dist (
    mkdir dist
)
copy BUILD\Release\altv-js-bytecode-compiler.lib dist
copy BUILD\Release\altv-js-bytecode-compiler.pdb dist
