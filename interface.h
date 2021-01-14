#pragma once

#include <string>

enum ErrorCode {
    OK,
    REPOSITORY_NOT_FOUND,
    BRANCH_NOT_FOUND,
    // More errors
};

class Error {
 public:
    Error(ErrorCode status_code, const std::string& description) :
            status_code(status_code),
            description(description) {}

    ErrorCode get_status_code() const {
        return status_code;
    }

    std::string get_description() const {
        return description;
    }

 private:
    ErrorCode status_code;
    std::string description;
};

class IExecutor {
 public:
    virtual Error clone_repository(const std::string& rep_name) = 0;
    virtual Error checkout_branch(const std::string& branch_name) = 0;
    virtual Error build_project(const std::string& params) = 0;
    virtual Error find_substring(const std::string& substring) = 0;
};