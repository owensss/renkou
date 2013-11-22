#ifndef UIMANAGER_H
#define UIMANAGER_H

class UiManager
{
public:
	enum page{
		mainWindow,
		customMadeArea,
		display,
		dia_accu_linetype1,
		dia_accu_linetype2,
		linetype1,
		linetype2,
		doingCalcProgress,
		enterCalculate,
		evaluate,
		importBasicData,
		importBasicPara,		
		newProject,
		projectName,
		progress_bar,
		searchObject
	};
public:
    UiManager();
	~UiManager();

	void active(page uiPage);
	void disactive(page uiPage);
	void makeFront(page uiPage);
private:
    uiPtr getUiPtr(page uiPage){
        uiPtr ptr = nullptr;
        if(!uiAlreadyExist(uiPage))
           ptr = addUiPtr(uiPage);
        else{

        }
            //TODO
    }

    /** create an object and insert the handle to ptrCollection
      */
    uiPtr addUiPtr(page uiPage);
    bool uiAlreadyExist(page uiPage) const {
        return ptrCollection.find(uiPage) !=  ptrCollection.end();
    }
private:
	typedef unique_ptr<QWidget *> uiPtr;
    typedef boost::ptr_map<page, QWidget> ptrContainer;
private:
    /** used for managing all kinds of ui ptrs
     */
    ptrContainer ptrCollection;
};

#endif // UIMANAGER_H
