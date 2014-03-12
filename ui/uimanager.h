#ifndef UIMANAGER_H
#define UIMANAGER_H

#include <QDialog>
#include <array>
#include <memory>

class UiManager
{
public:
  /*
   * Do Not Assign Value to enum items!
   * So That PAGE_SIZE == number of enum items could work
   */
    enum page {
//        customMadeArea,
        display,
//        dia_accu_linetype1,
//        dia_accu_linetype2,
//        linetype1,
//        linetype2,
//        doingCalcProgress,
        enterCalculate,
        evaluate,
        importBasicData,
        importBasicPara,
        newProject,
        openProject,
//        progress_bar,
        searchObject,
        PAGE_SIZE
    };
public:
    UiManager();
    ~UiManager();

    /**
     * @brief show the window
     * @param the window to show
     */
    void active(page uiPage);

    /**
     * @brief hide(close) a window
     * @param the window to hide
     */
    void disactive(page uiPage);

    /**
     * @brief show a window, force it to be focused
     * @param the window to be made front
     */
    void makeFront(page uiPage);
private:
    typedef std::shared_ptr<QDialog> uiPtr;

    /*
     * suppose one ui enum only has one instance
     */
    typedef std::array<uiPtr, PAGE_SIZE> PtrContainer;
private:
    /**
     * @brief get ui pointer from page
     * @param uiPage
     * @return the ui pointer
     */
    uiPtr get_ui(page uiPage){
        uiPtr ptr = ptrCollection[uiPage];
        if(ptr == nullptr)
           ptr = create_ui(uiPage);
        return ptr;
    }

    /**
     * @brief create ui, alloc memory.
     * @param uiPage
     * @return the pointer to created ui
     */
    uiPtr create_ui(page uiPage);

    /**
     * @brief check whether a page is created or not
     * @param uiPage
     * @return true if page is craeted. otherwise false
     */
    bool ui_exist(page uiPage) const {
      return ptrCollection[uiPage] != nullptr;
    }
private:
    /*
     * used for managing all kinds of ui ptrs
     */
    PtrContainer ptrCollection;
};

#endif // UIMANAGER_H
