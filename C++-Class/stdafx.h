#pragma once

#define _CRT_SECURE_NO_WARNINGS

// C
#include <stdio.h>
#include <assert.h>

// C++
#include <iostream>
#include <random>

#pragma warning(disable : 6031)

using namespace std;

#define SAFE_DELETE(p) { if(p) { delete(p); p = nullptr; } }
#define SAFE_DELETE_ARRAY(p) { if(p) { delete[](p); p = nullptr; } }