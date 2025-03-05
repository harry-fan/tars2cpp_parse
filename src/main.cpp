#include "TarsHelper.h"
#include "GMParam.h"
#include "tc_base64.h"
#include "tc_file.h"

void buildData() {
    ptars::GMParam param;
    param.puid = 1;
//    param.name = "test";
    param.serverId = 2;
    param.leagueUid = 3;

    string data = tarsToString(param);
    auto codestr = tars::TC_Base64::encode(data);
    tars::TC_File::save2file("tarstostr.txt", codestr);
}

void loadData() {
    auto str = tars::TC_File::load2str("tarstostr.txt");
    auto tarsstr = tars::TC_Base64::decode(str);
    cout << "load str:" << str << "|tarsstr:" << tarsstr << endl;
    auto tmp = stringToTars<ptars::GMParam>(tarsstr);
    cout << "string to tars:" << tmp.puid << "|" << tmp.serverId << "|" << tmp.leagueUid << endl;
}

/*
 * g++ --std=c++11 main.cpp -o main -I../util ../tars_cpp_utils.a
 * */
int main() {
    // buildData();
    loadData();
    return 0;
}