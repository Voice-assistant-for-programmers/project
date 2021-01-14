#pragma once

#include <iostream>
#include <string>
#include <cstdio>
#include <memory>
#include <stdexcept>
#include <array>

#include "interface.h"

class Executor : public IExecutor {
 public:
    explicit Executor(const std::string& path);
    Error clone_repository(const std::string& rep_name) override;
    Error checkout_branch(const std::string& branch_name) override;
    Error build_project(const std::string& params) override;
    Error find_substring(const std::string& substring) override;

 private:
    std::string exec(const char* cmd);
    std::string path;
};