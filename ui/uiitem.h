#ifndef UIITEM_H
#define UIITEM_H
#include "uimanager.h"

/** the parent of all ui
  * manage the handle to the uiManager
  */
class UiItem
{
public:
    UiItem();
    virtual ~UiItem();

    void setUiManager(UiManager* uiManager){
        this->uiManager = uiManager;
    }

    UiManager* getUiManager(){
        return uiManager;
    }
private:
    UiManager* uiManager;
};

#endif // UIITEM_H
