#include <QApplication>
#include <algorithm>
#include "uimanager.h"
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
  ptrCollection.fill(nullptr);
}

/** suppose the uiPage not existed before
  */
UiManager::uiPtr UiManager::create_ui(page uiPage){
    using namespace std;
    uiPtr ptr = nullptr;

    //create the ui object according to page value
    //TODO: the ctors of all ui need refining
    switch (uiPage) {
//        case customMadeArea :
//            ptr = make_shared<CustomMadeArea>(CustomMadeArea());
//            break;
        case display :{
            auto derived_ptr = new Display();
            derived_ptr->setUiManager(this);
            ptr = uiPtr(derived_ptr);}
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
        case enterCalculate:{
            auto derived_ptr = new EnterCalculate();
            derived_ptr->setUiManager(this);
            ptr = uiPtr(derived_ptr);}
            break;
        case evaluate:{
            auto derived_ptr = new Evaluate();
            derived_ptr->setUiManager(this);
            ptr = uiPtr(derived_ptr);}
            break;
        case importBasicData:{
            auto derived_ptr = new ImportBasicData();
            derived_ptr->setUiManager(this);
            ptr = uiPtr(derived_ptr);}
            break;
        case importBasicPara:{
            auto derived_ptr = new ImportBasicPara();
            derived_ptr->setUiManager(this);
            ptr = uiPtr(derived_ptr);}
            break;
        case newProject:{
            auto derived_ptr = new NewProject();
            derived_ptr->setUiManager(this);
            ptr = uiPtr(derived_ptr);}
            break;
        case openProject:{
                auto derived_ptr = new OpenProject();
                derived_ptr->setUiManager(this);
                ptr = uiPtr(derived_ptr);}
            break;
//        case progress_bar:
//            ptr = make_shared<Progress_bar>(Progress_bar());
//            break;
        case searchObject:{
            auto derived_ptr = new SearchObject();
            derived_ptr->setUiManager(this);
            ptr = uiPtr(derived_ptr);}
            break;
        default:
            break;
    }//end of switch
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
    get_ui(uiPage)->exec();
}
