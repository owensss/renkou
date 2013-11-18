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
        openProject,
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
};

#endif // UIMANAGER_H
