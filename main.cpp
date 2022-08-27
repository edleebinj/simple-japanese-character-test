#include<iostream>
#include<random>
#include<time.h>
#include<sstream>
#include<string>
using namespace std;
int main(){
    srand( time(NULL) );
    srand(rand());
    srand(rand());
    #define N 104
    int kind;
    cout << "輸入模式 1：平假名 2：片假名" << endl;
    cin >> kind;
    string japanese[N];
    int i =0;
    if(kind == 1){
        string line = "あ か さ た な は ま や ら わ い き し ち に ひ み り う く す つ ぬ ふ む ゆ る ん え け せ て ね へ め れ お こ そ と の ほ も よ ろ を が ざ だ ば ぱ ぎ じ ぢ び ぴ ぐ ず づ ぶ ぷ げ ぜ で べ ぺ ご ぞ ど ぼ ぽ きゃ ぎゃ しゃ じゃ ちゃ にゃ ひゃ びゃ ぴゃ みゃ りゃ きゅ ぎゅ しゅ じゅ ちゅ にゅ ひゅ びゅ ぴゅ みゅ りゅ きょ ぎょ しょ じょ ちょ にょ ひょ びょ ぴょ みょ りょ";
        
        i = 0;
        stringstream ssin(line);
        while (ssin.good() && i < N){
            ssin >> japanese[i];
            ++i;
        }
    }
    else if(kind == 2){
        string line = "ア カ サ タ ナ ハ マ ヤ ラ ワ イ キ シ チ ニ ヒ ミ リ ウ ク ス ツ ヌ フ ム ユ ル ン エ ケ セ テ ネ ヘ メ レ オ コ ソ ト ノ ホ モ ヨ ロ ヲ ガ ザ ダ バ パ ギ ジ ジ ビ ピ グ ズ ズ ブ プ ゲ ゼ デ ベ ペ ゴ ゾ ド ボ ポ キャ ギャ シャ ジャ チャ ニャ ヒャ ビャ ピャ ミャ リャ キュ ギュ シュ ジュ チュ ニュ ヒュ ビュ ピュ ミュ リュ キョ ギョ ショ ジョ チョ ニョ ヒョ ビョ ピョ ミョ リョ";
        i = 0;
        stringstream ssin(line);
        while (ssin.good() && i < N){
            ssin >> japanese[i];
            ++i;
        }
    }
    i = 0;
    string line2 = "a ka sa ta na ha ma ya ra wa i ki shi chi ni hi mi ri u ku su tsu nu fu mu yu ru n e ke se te ne he me re o ko so to no ho mo yo ro wo ga za da ba pa gi ji ji bi pi gu zu zu bu pu ge ze de be pe go zo do bo po kya gya sha ja cha nya hya bya pya mya rya kyu gyu shu ju chu nyu hyu byu pyu myu ryu kyo gyo sho jo cho nyo hyo byo pyo myo ryo";
    string eng[N];
    i = 0;
    stringstream ssin2(line2);
    while (ssin2.good() && i < N){
        ssin2 >> eng[i];
        ++i;
    }
    int mode;
    cout << "輸入模式 1：日文打中文 2：選擇日文 3：隨機生成拼音 4：答案模式" << endl;
    cin >> mode;
    int range;
    cout << "輸入範圍 1：清音 2：+濁音＆半濁音 3：+拗音" << endl;
    cin >> range;
    switch (range)
    {
    case 1:
        range = 46;
        break;
    case 2:
        range = 70;
        break;
    case 3: 
        range = 104;
        break;
    default:
        cout <<"不支援的範圍"<<endl;
        return 0;
        break;
    }
    
    cout <<"\n\n\n\n\n\n"<< "輸入 87 看你錯了什麼並結束程式"<<endl;
    bool isBreak = false;
    if(mode == 1){
        bool wrong[104] = {0};
        while(true){
            int temp = rand()%range;
            cout << japanese[temp] << ":\n" << flush;
            string str;
            cin >> str;
            if(str == "87"){
                for(int i = 0; i < 104; i++){
                    if(wrong[i])cout << japanese[i]<<":"<<eng[i] << " ";
                }
                isBreak = true;
                break;
            }
            else if(str == eng[temp]){
                cout << "答對！！！！！！！！！！"<<""<<endl;
            }
            else{
                cout << eng[temp] << " 才是答案！"<<endl;
                wrong[temp] = true;
            }
        }
    }
    else if(mode == 2){
        cout << "模式還沒做"<<endl;
    }
    else if(mode == 3){
        while(true){
            int temp = rand()%range;
            cout << eng[temp] << ":\n" << flush;
            string str;
            cin >> str;
            cout << japanese[temp] << "\n" << flush;
            if(str == "87")break;
        }
    }
    else if(mode == 4){
        while(true){
            cout <<"輸入拼音" << endl;
            bool found = false;
            string str;
            cin >> str;
            if(str == "87")break;
            for(int i = 0; i < N; i++){
                if(str == eng[i]){
                    cout << japanese[i] <<endl;
                    found = true;
                }
            }
            if(found == false)cout << "未知"<<endl;
        }
    }
    else{
        if(!isBreak)cout << "模式不存在"<<endl;
        return 0;
    }
}
