#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <windows.h>
using namespace std;

int main()
{
    int chance, chvalue;
    string commands = "";
    srand(time(NULL));

    //Crosshair generation
    //other
    commands += "cl_crosshair_recoil " + to_string(rand() % 2) + ";\n";                //cl_crosshair_recoil            
    commands += "cl_crosshair_friendly_warning " + to_string(rand() % 2) + ";\n";      //cl_crosshair_friendly_warning   

    //shape
    commands += "cl_crosshairdot " + to_string(rand() % 2) + ";\n";                    //cl_crosshairdot                 
    commands += "cl_crosshair_t " + to_string(rand() % 2) + ";\n";                     //cl_crosshair_t                  
    commands += "cl_crosshairgap_useweaponvalue " + to_string(rand() % 2) + ";\n";     //cl_crosshairgap_useweaponvalue  
    chance = rand() % 18 + 1;
    if (chance <= 5) chvalue = rand() % 11;
    else if (chance <= 10) chvalue = rand() % 40 + 11;                                 //yandere dev moment :(
    else if (chance <= 14) chvalue = rand() % 50 + 51;
    else if (chance <= 17) chvalue = rand() % 200 + 101;
    else chvalue = rand() % 600 + 301;
    if ((rand() % 5) == 4) chvalue *= -1;
    commands += "cl_crosshairgap " + to_string(chvalue) + ";\n";                       //cl_crosshairgap               

    chance = rand() % 14 + 1;
    if (chance <= 4) chvalue = rand() % 6;
    else if (chance <= 8) chvalue = rand() % 10 + 6;
    else if (chance <= 11) chvalue = rand() % 15 + 16;
    else if (chance <= 13) chvalue = rand() % 70 + 31;
    else chvalue = rand() % 400 + 101;
    commands += "cl_crosshairsize " + to_string(chvalue) + ";\n";                      //cl_crosshairsize                

    chance = rand() % 24 + 1;
    if (chance <= 4) chvalue = rand() % 11;
    else if (chance <= 9) chvalue = rand() % 20 + 11;
    else if (chance <= 13) chvalue = rand() % 20 + 31;
    else if (chance <= 16) chvalue = rand() % 50 + 51;
    else if (chance <= 19) chvalue = rand() % 100 + 101;
    else if (chance <= 21) chvalue = rand() % 300 + 201;
    else if (chance <= 23) chvalue = rand() % 500 + 501;
    else chvalue = rand() % 7000 + 1001;
    commands += "cl_crosshairthickness " + to_string((float)chvalue / 10).substr(0, 3) + ";\n";             //cl_crosshairthickness     

    //color
    commands += "cl_crosshair_drawoutline " + to_string(chance = rand() % 2) + ";\n";                       //cl_crosshair_drawoutline
    if (chance == 1) commands += "cl_crosshair_outlinethickness " + to_string(rand() % 3 + 1) + ";\n";      //cl_crosshair_outlinethickness
    commands += "cl_crosshairusealpha 1;\n";                                                                //cl_crosshairusealpha             
                                                                                                            
    chance = rand() % 5 + 1;
    if (chance <= 1) chvalue = rand() % 101;
    else if (chance <= 3) chvalue = rand() % 130 + 101;
    else chvalue = rand() % 25 + 231;
    commands += "cl_crosshairalpha " + to_string(chvalue) + ";\n";                      //cl_crosshairalpha             

    commands += "cl_crosshaircolor 5;\n";                                               //cl_crosshaircolor             
    commands += "cl_crosshaircolor_r " + to_string(rand() % 256) + ";\n";               //cl_crosshaircolor_r                
    commands += "cl_crosshaircolor_g " + to_string(rand() % 256) + ";\n";               //cl_crosshaircolor_g           
    commands += "cl_crosshaircolor_b " + to_string(rand() % 256) + ";\n";               //cl_crosshaircolor_b           

    //dynamics
    int A[3] = { 2,4,5 };
    commands += "cl_crosshairstyle " + to_string(A[chance = rand() % 3]) + ";\n";       //cl_crosshairstyle             
    if (A[chance] == 2)
    {
        commands += "cl_crosshair_dynamic_maxdist_splitratio " + to_string(float(rand() % 11) / 10).substr(0, 3) + ";\n";           //cl_crosshair_dynamic_maxdist_splitratio
        commands += "cl_crosshair_dynamic_splitalpha_innermod " + to_string(float(rand() % 11) / 10).substr(0, 3) + ";\n";          //cl_crosshair_dynamic_splitalpha_innermod
        commands += "cl_crosshair_dynamic_splitalpha_outermod " + to_string(float(rand() % 11) / 10).substr(0, 3) + ";\n";          //cl_crosshair_dynamic_splitalpha_outermod

        chance = rand() % 8 + 1;
        if (chance <= 2) chvalue = rand() % 3 + 1;
        else if (chance <= 5) chvalue = rand() % 7 + 4;
        else if (chance <= 7) chvalue = rand() % 40 + 11;
        else chvalue = rand() % 50 + 51;
        commands += "cl_crosshair_dynamic_splitdist " + to_string(chvalue) + ";\n";             //cl_crosshair_dynamic_splitdist
    }

    //Copy to clipboard (le stolen code, sorry: https://www.reddit.com/r/learnprogramming/comments/hs74l/copying_a_string_to_the_clipboard_in_c/)
    const char* output = commands.c_str();
    const size_t len = strlen(output) + 1;
    HGLOBAL hMem = GlobalAlloc(GMEM_MOVEABLE, len);
    memcpy(GlobalLock(hMem), output, len);
    GlobalUnlock(hMem);
    OpenClipboard(0);
    EmptyClipboard();
    SetClipboardData(CF_TEXT, hMem);
    CloseClipboard();
}
