/*
 * File:    window.cpp
 * Author:  Enrique Najera
 * Purpose: Holds & creates window gadgets
 *          Solves for mean, median mode
 *          Implement QVector, QSet, QMap to solve.
 * 04 November 2015
 */

// USER_LIBS
#include "window.h"

// Start constructor Window
Window::Window()
{
    // Create labels and text boxes
    lbl_arySize = new QLabel(tr("Enter &array size: "));
    aryTxtBox = new QLineEdit;
    lbl_arySize->setBuddy(aryTxtBox);
    lbl_modNum = new QLabel(tr("Enter &mod number: "));
    modTxtBox = new QLineEdit;
    lbl_modNum->setBuddy(modTxtBox);

    lbl_initAry = new QLabel(tr("Initial Array: "));
    initTxtBox = new QLineEdit;
    initTxtBox->setReadOnly(true);
    lbl_output = new QLabel(tr("Result: "));
    outTxtBox = new QLineEdit;
    outTxtBox->setReadOnly(true);

    // Create buttons
    btn_mean = new QPushButton(this);
    btn_mean->setText("Mean");
    btn_median = new QPushButton(this);
    btn_median->setText("Median");
    btn_mode = new QPushButton(this);
    btn_mode->setText("Mode");
    btn_cancel = new QPushButton(this);
    btn_cancel->setText("Cancel");

    // Connections
    connect(btn_mean,   SIGNAL(clicked()), this, SLOT(mean()));
    connect(btn_median, SIGNAL(clicked()), this, SLOT(median()));
    connect(btn_mode,   SIGNAL(clicked()), this, SLOT(mode()));
    connect(btn_cancel, SIGNAL(clicked()), this, SLOT(close()));

    // Layout
    layout_topAry = new QHBoxLayout();
    layout_topAry->addWidget(lbl_arySize);
    layout_topAry->addWidget(aryTxtBox);
    layout_topAry->setSpacing(17);

    layout_topMod = new QHBoxLayout();
    layout_topMod->addWidget(lbl_modNum);
    layout_topMod->addWidget(modTxtBox);
    layout_topMod->setSpacing(5);

    layout_middle = new QVBoxLayout();
    layout_middle->addWidget(btn_mean);
    layout_middle->addWidget(btn_median);
    layout_middle->addWidget(btn_mode);
    layout_middle->addWidget(btn_cancel);

    layout_bottomInit = new QHBoxLayout();
    layout_bottomInit->addWidget(lbl_initAry);
    layout_bottomInit->addWidget(initTxtBox);

    layout_bottomOut = new QHBoxLayout();
    layout_bottomOut->addWidget(lbl_output);
    layout_bottomOut->addWidget(outTxtBox);
    layout_bottomOut->setSpacing(32);

    layout_main = new QVBoxLayout();
    layout_main->addLayout(layout_topAry);
    layout_main->addLayout(layout_topMod);
    layout_main->addLayout(layout_middle);
    layout_main->addLayout(layout_bottomInit);
    layout_main->addLayout(layout_bottomOut);

    setLayout(layout_main);

    setFixedSize(200,260);
}// End constructor Window

// Start method mean uses QVector
void Window::mean()
{
    setWindowTitle("MEAN");

    // Declare variables
    int temp = 0; // Holds array value for adding

    // Clear text for new array
    initTxtBox->clear();

    // Convert string to int
    arySize = aryTxtBox->text().toInt();
    modNum  = modTxtBox->text().toInt();

    // If input is empty or <=0, program crashes
    // therefore exit function and output error
    if (arySize <= 0 || modNum <= 0)
    {
        outTxtBox->setText("Inputs must be > 0!");
        return;
    }

    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));

    // Fill array
    QVector<int> array(arySize);
    for (int i = 0; i < arySize; i++)
    {
        array[i] = rand() % modNum;
    }

    // Sort array
    std::sort(array.begin(), array.end());

    // Output sorted array
    for (int i = 0; i < arySize; i++)
    {
        initTxtBox->insert(QString::number(array[i]) + " ");
    }

    // Find mean
    for (int i = 0; i <= arySize - 1; i++)
    {
        temp += array[i];
    }

    lbl_output->setText("Mean: ");
    layout_bottomOut->setSpacing(36);
    outTxtBox->setText(QString::number(temp / arySize));
}// End method mean

// Start method median uses QSet
void Window::median()
{
    setWindowTitle("MEDIAN");

    // Declare Variables
    int temp; // Holds number for index

    // Clear text for new array
    initTxtBox->clear();

    // Convert string to int
    arySize = aryTxtBox->text().toInt();
    modNum  = modTxtBox->text().toInt();

    // If input is empty or <=0, program crashes
    // therefore exit function and output error
    if (arySize <= 0 || modNum <= 0)
    {
        outTxtBox->setText("Inputs must be > 0!");
        return;
    }

    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));

    // Fill array
    QVector<int> arraySet(arySize);
    //QSet<int> arraySet;
    for (int i = 0; i < arySize; i++)
    {
        arraySet[i] = rand() % modNum;
    }

    // Sort array
    std::sort(arraySet.begin(), arraySet.end());

    // Output sorted array
    /*foreach ( const int &value, arraySet)
        initTxtBox->insert(QString::number(value) + " ");*/
    for (int i = 0; i < arySize; i++)
    {
        initTxtBox->insert(QString::number(arraySet[i]) + " ");
    }

    // Find middle number
    temp = arySize / 2;

    lbl_output->setText("Median: ");
    layout_bottomOut->setSpacing(28);
    // If array size is odd, output one number
    if (arySize % 2 == 1 )
        outTxtBox->setText(QString::number(arraySet[temp]));
    // If array size is even, output two numbers
    else if (arySize % 2 == 0)
        outTxtBox->setText(QString::number(arraySet[temp - 1])
                           + " & "
                           +QString::number(arraySet[temp]));
}// End method median

// Start methos mode uses QMap
void Window::mode()
{
    setWindowTitle("MODE");

    // Declare Variables
    int num     = 0, // Holds array number for comparison
        mode    = 0, // Holds the mode
        counter = 1, // Counts occurences of num
        cntMode = 1; // Counts mode

    // Clear text for new array
    initTxtBox->clear();

    // Convert string to int
    arySize = aryTxtBox->text().toInt();
    modNum  = modTxtBox->text().toInt();

    // If input is empty or <=0, program crashes
    // therefore exit function and output error
    if (arySize <= 0 || modNum <= 0)
    {
        outTxtBox->setText("Inputs must be > 0!");
        return;
    }

    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));

    // Fill array
    QVector<int> arrayMap(arySize);
    //QMap<QString, int> arrayMap;

    for (int i = 0; i < arySize; i++)
    {
        arrayMap[i] = rand() % modNum;
    }

    // Sort array
    std::sort(arrayMap.begin(), arrayMap.end());

    // Output sorted array
    for (int i = 0; i < arySize; i++)
    {
        initTxtBox->insert(QString::number(arrayMap[i]) + " ");
    }


    // Calculate mode
    num = arrayMap[0];
    mode = num;

    for (int i = 1; i < arySize; ++i)
    {
        if (arrayMap[i] == num)
        {
            ++counter;
            if (counter > cntMode)
            {
                cntMode = counter;
                mode = num;
            }
        }
        else
        {
            num = arrayMap[i];
            counter = 1;
        }// End else
    }// End for

    lbl_output->setText("Mode: ");
    layout_bottomOut->setSpacing(36);

    outTxtBox->setText(QString::number(mode));
}// End method mode
