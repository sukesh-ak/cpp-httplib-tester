#include <iostream>
#include "httplib.h"

int main() {
    #ifdef CPPHTTPLIB_OPENSSL_SUPPORT
        httplib::SSLClient cli("jsonplaceholder.typicode.com");
        cli.enable_server_certificate_verification(true);
        std::cout << "HTTPS" << std::endl;
    #else
        httplib::Client cli("jsonplaceholder.typicode.com");
        std::cout << "HTTP" << std::endl;
    #endif

    if (auto res = cli.Get("/todos/1")) {
        if (res->status == 200) {
          std::cout << res->body << std::endl;
        }
    }
    return 0;
}
