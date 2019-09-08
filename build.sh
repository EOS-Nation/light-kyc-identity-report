#!/usr/bin/env bash

mkdir -p dist
eosio-cpp -abigen -R resource -o ./dist/identity.wasm -I include src/identity.cpp
