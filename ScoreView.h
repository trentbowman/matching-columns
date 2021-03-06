// ScoreView.h
// The High Score View header for MatchColumns.proj
// by: Scott Jacovidis  scottybe2012@gmail.com
// See ReadMe for program details.

#include <View.h>
#include <Entry.h>
#include <File.h>
#include <List.h>
#include <TextControl.h>
#include <Button.h>

#ifndef _ScoreView_

class SaveData
{
public: 
  char name[15];
  int32 score;
  int boardX;
  int boardY;

};

class ScoreView : public BView
{
public:
	ScoreView(BRect size, int totX, int totY);
	~ScoreView(void);
	bool IsDismissed(void); 
	void Display(int x, int32 xSc = -1);
	void AddToHighScore(void);
	//virtual void AttachedToWindow(void);
	virtual void Draw(BRect updateRect);
	

private:
	void LoadScores(void);
	void SaveScores(void);
	bool IsAHighScore(int32 x);
	void PrintHighScores(void);
	void NewHSList(void);
	int totalX, totalY;
	int32 curScore;
	BPath *xPath;
	//entry_ref appRef;
	bool isDismissed;
	BFile *xFile;
	BButton *btnSave;
	BButton *btnCancel;
	BButton *btnOk;
	BTextControl *txcNameEntry;
	SaveData Scores[10];
};

#define _ScoreView_
#endif