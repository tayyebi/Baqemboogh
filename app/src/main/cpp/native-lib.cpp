#include <jni.h>
#include <string>
#include "BTree.h"

void InOrder(node *Root, bool FilterMeaning, std::string &result);
bool  FirstFound;
BTree  *words;
node * TreeRootNode;

extern "C"
JNIEXPORT jstring JNICALL




Java_com_gordarg_rexa_baqemboogh_MainActivity_Translate(JNIEnv *env, jobject instance,
                                                        jstring Word_) {
    const char *Word = env->GetStringUTFChars(Word_, 0);


    //*** LOGIC

    node * searchedResult = words->Search(Word);
    const char *returnValue;
    if (searchedResult == NULL)
        returnValue = "Not found!";
    else
    {
        std::string InOrderResult;
        FirstFound = false;
        InOrder(searchedResult,true,  InOrderResult);
        returnValue = InOrderResult.c_str();
    }

    //*** END LOGIC

    return env->NewStringUTF(returnValue);
}



void InOrder(node *Root, bool SearchMeanings, std::string &result) {
    if (!Root)
        return;
    if (FirstFound && !Root->IsMeaning)
        return;

    InOrder(Root->Left,SearchMeanings, result);
    if (SearchMeanings&& Root->IsMeaning)
    {
        FirstFound = true;
        result += Root->Key + "\n";
    }
    else if( !SearchMeanings&& !Root->IsMeaning)
    {
        result += Root->Key + "\n";
    }
    InOrder(Root->Right, SearchMeanings, result);

}

extern "C"
JNIEXPORT void JNICALL
Java_com_gordarg_rexa_baqemboogh_MainActivity_Load(JNIEnv *env, jobject instance) {


    words = new  BTree();

    TreeRootNode = words->Insert("baqemboogh", false);
    words->Insert("Egg", true, TreeRootNode);

    words->Insert("Melon", true, words->Insert("vargaze", false));
    words->Insert("Kharboze", true, words->Search("vargaze"));

    words->Insert("Watermelon", true,  words->Insert("endehe", false));

    words->Insert("Vacuum cleaner", true,  words->Insert("budasti", false));
    words->Insert("Jaroo Dasti", true,  words->Search("budasti"));
    words->Insert("Jaroo Barghi", true,  words->Search("budasti"));

    words->Insert("Lamp", true,   words->Insert("chiakh", false));
    words->Insert("Friend", true,   words->Insert("faghid", false));

}extern "C"
JNIEXPORT jstring JNICALL
Java_com_gordarg_rexa_baqemboogh_MainActivity_Hint(JNIEnv *env, jobject instance) {
    const char *returnValue;
    std::string InOrderResult;
    FirstFound = false;
    InOrder(TreeRootNode,false,  InOrderResult);
    returnValue = InOrderResult.c_str();
    return env->NewStringUTF(returnValue);
}