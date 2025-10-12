#!/bin/bash

# Simple F5 build and run script
echo "🔄 F5 Build & Run triggered!"

# Use Makefile's build-run target which will:
# 1. Clean old files (including executable)
# 2. Build new executable 
# 3. Run the program
make build-run