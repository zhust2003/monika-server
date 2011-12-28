#! /bin/bash
cd ~/monika/build/bin
valgrind --leak-check=full --show-reachable=yes --num-callers=40 --track-origins=yes ./monika $* 2>&1
