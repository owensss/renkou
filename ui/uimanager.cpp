#include "uimanager.h"



UiManager::UiManager()
{
}

<<<<<<< HEAD
UiManager::uiPtr UiManager::addUiPtr(page uiPage){
    uiPtr ptr = nullptr;

    //create the ui object according to page value
    //TODO: the ctors of all ui need refining
    switch (uiPage) {
        case mainWindow :
            ptr = new MainWindow(this);
            break;
        case customMadeArea :
            ptr = new CustomMadeArea(this);
            break;
        case display :
            ptr = new Display(this);
            break;
        case dia_accu_linetype1:
            ptr = new Dia_accu_linetype1(this);
            break;
        case dis_accu_linetype2:
            ptr = new Dia_accu_linetype2(this);
            break;
        case linetype1:
            ptr = new Linetype1(this);
            break;
        case linetype2:
            ptr = new Linetype2(this);
            break;
        case doingCalcProgress:
            ptr = new DoingCalcProgress(this);
            break;
        case enterCalculate:
            ptr = new EnterCalculate(this);
            break;
        case evaluate:
            ptr = new Evaluate(this);
            break;
        case importBasicData:
            ptr = new ImportBasicData(this);
            break;
        case importBasicPara:
            ptr = new importBasicData(this);
            break;
        case newProject:
            ptr = new NewProject(this);
            break;
        case projectName:
            ptr = new ProjectName(this);
            break;
        case progress_bar:
            ptr = new Progress_bar(this);
            break;
        case searchObject:
            ptr = new SearchObject(this);
            break;
    }//end of switch
    ptrCollection.insert(uiPage, ptr);
}

void UiManager::active(page uiPage){
    //TODO
}
=======
UiManager::~UiManager()
{

}
void UiManager::active(UiManager::page uiPage)
{

}

void UiManager::disactive(UiManager::page uiPage)
{

}

void UiManager::makeFront(UiManager::page uiPage)
{

}

>>>>>>> 50c1e71e0d3aaab919de479af75f5c2d8a176851
