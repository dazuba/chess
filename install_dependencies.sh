#!/bin/bash

mkdir tmp
cd tmp

sudo apt update

sudo apt install git
sudo apt install gcc
sudo apt install g++
sudo apt install cmake
sudo apt install libjsoncpp-dev
sudo apt install uuid-dev
sudo apt install openssl
sudo apt install libssl-dev
sudo apt install zlib1g-dev

git clone https://github.com/drogonframework/drogon.git
cd drogon

sudo ./build.sh
cd ..

sudo apt install libqt6svg6-dev
sudo apt install qt6-base-dev

cd ..
rm -rf tmp
