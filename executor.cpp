#include "exectutor.h"

Executor::Executor(const std::string& path) : path(path) {}

Error Executor::clone_repository(const std::string& rep_name) {
    std::string command = "git clone " + rep_name;
    std::string result = exec(command.c_str());

    if (result.find("fatal") == std::string::npos) {
        return Error(ErrorCode::REPOSITORY_NOT_FOUND, result);
    } else if (result.find("done") == std::string::npos) {
        return Error(ErrorCode::OK, result);
    }

    return Error(ErrorCode::OK, result);
}

Error Executor::checkout_branch(const std::string& branch_name) {
    std::string command = "git checkout " + branch_name;

    std::string result = exec(command.c_str());
    if (result.find("error") == std::string::npos) {
        return Error(ErrorCode::BRANCH_NOT_FOUND, result);
    }

    return Error(ErrorCode::OK, result);
}

Error Executor::build_project(const std::string& params) {
    std::string command = "make " + params;
    return Error(ErrorCode::OK, exec(command.c_str()));
}

Error Executor::find_substring(const std::string& substring) {
    std::string command = "ls | grep " + substring;
    return Error(ErrorCode::OK, exec(command.c_str()));
}

std::string Executor::exec(const char* cmd) {
    std::array<char, 128> buffer;
    std::string result;
    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
    if (!pipe) {
        throw std::runtime_error("popen() failed!");
    }
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        result += buffer.data();
    }

    return result;
}