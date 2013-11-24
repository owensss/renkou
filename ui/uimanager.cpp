#include "uimanager.h"
#include "mainwindow.h"
#include "display.h"
#include "entercalculate.h"
#include "evaluate.h"
#include "importbasicdata.h"
#include "importbasicpara.h"
#include "newproject.h"
#include "openproject.h"
#include "searchobject.h"

UiManager::UiManager()
{
  ptrContainer.fill(nullptr);
  create_ui(mainWindow);
}

/** suppose the uiPage not existed before
  */
UiManager::uiPtr UiManager::create_ui(page uiPage){
    using namespace std;
    uiPtr ptr = nullptr;

    //create the ui object according to page value
    //TODO: the ctors of all ui need refining
    switch (uiPage) {
        case mainWindow :
            ptr = make_shared<MainWindow>(MainWindow());
            break;
//        case customMadeArea :
//            ptr = make_shared<CustomMadeArea>(CustomMadeArea());
//            break;
        case display :
            ptr = make_shared<Display>(Display());
            break;
//        case dia_accu_linetype1:
//            ptr = make_shared<Dia_accu_linetype1>(Dia_accu_linetype1());
//            break;
//        case dis_accu_linetype2:
//            ptr = make_shared<Dia_accu_linetype2>(Dia_accu_linetype2());
//            break;
//        case linetype1:
//            ptr = make_shared<Linetype1>(Linetype1());
//            break;
//        case linetype2:
//            ptr = make_shared<Linetype2>(Linetype2());
//            break;
//        case doingCalcProgress:
//            ptr = make_shared<DoingCalcProgress>(DoingCalcProgress());
//            break;
        case enterCalculate:
            ptr = make_shared<EnterCalculate>(EnterCalculate());
            break;
        case evaluate:
            ptr = make_shared<Evaluate>(Evaluate());
            break;
        case importBasicData:
            ptr = make_shared<ImportBasicData>(ImportBasicData());
            break;
        case importBasicPara:
            ptr = make_shared<importBasicPara>(importBasicPara());
            break;
        case newProject:
            ptr = make_shared<newProject>(newProject());
            break;
//        case projectName:
//            ptr = make_shared<projectName>(projectName());
//            break;
//        case progress_bar:
//            ptr = make_shared<Progress_bar>(Progress_bar());
//            break;
        case searchObject:
            ptr = make_shared<SearchObject>(SearchObject());
            break;
    }//end of switch
    ptr->setUiManager(this);
    ptrCollection[uiPage] = ptr;

    return ptr;
}

UiManager::~UiManager()
{
}

void UiManager::active(UiManager::page uiPage)
{
    get_ui(uiPage)->show();
}

void UiManager::disactive(UiManager::page uiPage)
{
    get_ui(uiPage)->hide();
}

void UiManager::makeFront(UiManager::page uiPage)
{
    get_ui(uiPage)->execute();
}

