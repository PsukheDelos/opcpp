//****************************************************************
// Copyright (C) 2008 OP Games LLC - All Rights Reserved
//
// Authors: Kevin Depue & Lucas Ellis
//
// File: opWideString.h
// Date: 10/08/2008
//
// Description:
//
// wrapper for wide char strings
//****************************************************************

#pragma once

#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include "opcpp/opstl/opstlcommon.h"

namespace opstl {

/**** wrapper for stl string class ****/

class opWideString {
   public:
    /**** construction ****/

    opWideString() {}

    opWideString(const opWideString& _s) : s(_s.s) {}

    opWideString(const opString& _s)
        : s(_s.GetString().begin(), _s.GetString().end()) {}

    opWideString(const string& _s) : s(_s.begin(), _s.end()) {}

    opWideString(const wstring& _s) : s(_s) {}

    opWideString(wchar_t c) { s = c; }

    opWideString(const wchar_t* c) { s = c; }

    opWideString(char c) { s = c; }

    opWideString(const char* c) {
        s = opWideString(opString(c)).GetWideString();
    }

    std::wstring& GetWideString() { return s; }

    const std::wstring& GetWideString() const { return s; }

    const wchar_t* GetCString() const { return s.c_str(); }

    int Size() const { return (int)s.size(); }

    opWideString& operator+=(const opWideString& _s) {
        s += _s.s;
        return *this;
    }

    opWideString operator+(const opWideString& _s) const {
        opWideString ws = *this;
        ws += _s;
        return ws;
    }

   private:
    std::wstring s;
};

}  // end namespace opstl
