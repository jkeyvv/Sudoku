/********************************************************************************
** Form generated from reading UI file 'window.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOW_H
#define UI_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "table.h"

QT_BEGIN_NAMESPACE

class Ui_WindowClass
{
public:
    QAction *game;
    QAction *calculator;
    QAction *rules;
    QAction *about;
    QAction *easy;
    QAction *difficult;
    QAction *professional;
    QWidget *centralWidget;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    Table *tableWidget;
    QGridLayout *gridLayout;
    QLabel *label;
    QLCDNumber *timer;
    QLabel *label_3;
    QComboBox *modebox;
    QLabel *label_2;
    QComboBox *difficultybox;
    QPushButton *startbutton;
    QPushButton *submitbutton;
    QPushButton *rankbutton;
    QPushButton *aboutbutton;

    void setupUi(QMainWindow *WindowClass)
    {
        if (WindowClass->objectName().isEmpty())
            WindowClass->setObjectName(QStringLiteral("WindowClass"));
        WindowClass->resize(470, 290);
        WindowClass->setMinimumSize(QSize(470, 290));
        WindowClass->setMaximumSize(QSize(470, 290));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(9);
        WindowClass->setFont(font);
        WindowClass->setAcceptDrops(false);
        WindowClass->setAutoFillBackground(false);
        WindowClass->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        game = new QAction(WindowClass);
        game->setObjectName(QStringLiteral("game"));
        game->setCheckable(true);
        game->setChecked(true);
        game->setEnabled(true);
        calculator = new QAction(WindowClass);
        calculator->setObjectName(QStringLiteral("calculator"));
        calculator->setCheckable(true);
        rules = new QAction(WindowClass);
        rules->setObjectName(QStringLiteral("rules"));
        about = new QAction(WindowClass);
        about->setObjectName(QStringLiteral("about"));
        easy = new QAction(WindowClass);
        easy->setObjectName(QStringLiteral("easy"));
        easy->setCheckable(true);
        easy->setChecked(true);
        easy->setMenuRole(QAction::TextHeuristicRole);
        difficult = new QAction(WindowClass);
        difficult->setObjectName(QStringLiteral("difficult"));
        difficult->setCheckable(true);
        difficult->setChecked(false);
        professional = new QAction(WindowClass);
        professional->setObjectName(QStringLiteral("professional"));
        professional->setCheckable(true);
        centralWidget = new QWidget(WindowClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 474, 272));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        tableWidget = new Table(layoutWidget);
        if (tableWidget->columnCount() < 9)
            tableWidget->setColumnCount(9);
        if (tableWidget->rowCount() < 9)
            tableWidget->setRowCount(9);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tableWidget->sizePolicy().hasHeightForWidth());
        tableWidget->setSizePolicy(sizePolicy);
        tableWidget->setMinimumSize(QSize(270, 270));
        tableWidget->setMaximumSize(QSize(270, 270));
        QFont font1;
        font1.setPointSize(12);
        tableWidget->setFont(font1);
        tableWidget->viewport()->setProperty("cursor", QVariant(QCursor(Qt::ArrowCursor)));
        tableWidget->setAcceptDrops(false);
        tableWidget->setFrameShape(QFrame::StyledPanel);
        tableWidget->setFrameShadow(QFrame::Sunken);
        tableWidget->setLineWidth(0);
        tableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget->setEditTriggers(QAbstractItemView::AnyKeyPressed|QAbstractItemView::EditKeyPressed);
        tableWidget->setRowCount(9);
        tableWidget->setColumnCount(9);
        tableWidget->horizontalHeader()->setVisible(false);
        tableWidget->horizontalHeader()->setDefaultSectionSize(30);
        tableWidget->horizontalHeader()->setMinimumSectionSize(30);
        tableWidget->horizontalHeader()->setProperty("showSortIndicator", QVariant(true));
        tableWidget->horizontalHeader()->setStretchLastSection(true);
        tableWidget->verticalHeader()->setVisible(false);
        tableWidget->verticalHeader()->setMinimumSectionSize(30);

        horizontalLayout->addWidget(tableWidget);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(14);
        font2.setBold(false);
        font2.setWeight(50);
        label->setFont(font2);
        label->setCursor(QCursor(Qt::ArrowCursor));
        label->setLayoutDirection(Qt::LeftToRight);
        label->setAutoFillBackground(false);
        label->setFrameShape(QFrame::NoFrame);
        label->setFrameShadow(QFrame::Plain);
        label->setTextFormat(Qt::AutoText);
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        timer = new QLCDNumber(layoutWidget);
        timer->setObjectName(QStringLiteral("timer"));
        QSizePolicy sizePolicy1(QSizePolicy::Ignored, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(timer->sizePolicy().hasHeightForWidth());
        timer->setSizePolicy(sizePolicy1);
        timer->setMaximumSize(QSize(16777215, 35));
        QFont font3;
        font3.setPointSize(13);
        timer->setFont(font3);
        timer->setCursor(QCursor(Qt::ArrowCursor));
        timer->setFrameShadow(QFrame::Raised);
        timer->setDigitCount(5);
        timer->setMode(QLCDNumber::Oct);
        timer->setSegmentStyle(QLCDNumber::Flat);

        gridLayout->addWidget(timer, 0, 1, 1, 1);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy2);
        QFont font4;
        font4.setPointSize(14);
        label_3->setFont(font4);
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        modebox = new QComboBox(layoutWidget);
        modebox->addItem(QString());
        modebox->addItem(QString());
        modebox->setObjectName(QStringLiteral("modebox"));
        modebox->setEnabled(true);
        sizePolicy1.setHeightForWidth(modebox->sizePolicy().hasHeightForWidth());
        modebox->setSizePolicy(sizePolicy1);
        modebox->setMaximumSize(QSize(87, 16777215));
        QFont font5;
        font5.setPointSize(10);
        modebox->setFont(font5);
        modebox->setCursor(QCursor(Qt::PointingHandCursor));
        modebox->setFocusPolicy(Qt::ClickFocus);
        modebox->setLayoutDirection(Qt::LeftToRight);
        modebox->setAutoFillBackground(false);
        modebox->setEditable(false);
        modebox->setInsertPolicy(QComboBox::InsertAtBottom);
        modebox->setSizeAdjustPolicy(QComboBox::AdjustToMinimumContentsLengthWithIcon);

        gridLayout->addWidget(modebox, 1, 1, 1, 1);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        sizePolicy2.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy2);
        label_2->setFont(font4);
        label_2->setFrameShape(QFrame::NoFrame);
        label_2->setFrameShadow(QFrame::Plain);
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        difficultybox = new QComboBox(layoutWidget);
        difficultybox->addItem(QString());
        difficultybox->addItem(QString());
        difficultybox->addItem(QString());
        difficultybox->setObjectName(QStringLiteral("difficultybox"));
        sizePolicy1.setHeightForWidth(difficultybox->sizePolicy().hasHeightForWidth());
        difficultybox->setSizePolicy(sizePolicy1);
        difficultybox->setFont(font5);
        difficultybox->setCursor(QCursor(Qt::PointingHandCursor));
        difficultybox->setFocusPolicy(Qt::ClickFocus);
        difficultybox->setInsertPolicy(QComboBox::InsertAtBottom);
        difficultybox->setSizeAdjustPolicy(QComboBox::AdjustToContentsOnFirstShow);

        gridLayout->addWidget(difficultybox, 2, 1, 1, 1);

        startbutton = new QPushButton(layoutWidget);
        startbutton->setObjectName(QStringLiteral("startbutton"));
        sizePolicy.setHeightForWidth(startbutton->sizePolicy().hasHeightForWidth());
        startbutton->setSizePolicy(sizePolicy);
        startbutton->setFont(font3);
        startbutton->setCursor(QCursor(Qt::PointingHandCursor));
        startbutton->setFocusPolicy(Qt::ClickFocus);

        gridLayout->addWidget(startbutton, 3, 0, 1, 1);

        submitbutton = new QPushButton(layoutWidget);
        submitbutton->setObjectName(QStringLiteral("submitbutton"));
        sizePolicy.setHeightForWidth(submitbutton->sizePolicy().hasHeightForWidth());
        submitbutton->setSizePolicy(sizePolicy);
        submitbutton->setFont(font3);
        submitbutton->setCursor(QCursor(Qt::PointingHandCursor));
        submitbutton->setFocusPolicy(Qt::ClickFocus);
        submitbutton->setContextMenuPolicy(Qt::DefaultContextMenu);
        submitbutton->setAutoDefault(false);
        submitbutton->setFlat(false);

        gridLayout->addWidget(submitbutton, 3, 1, 1, 1);

        rankbutton = new QPushButton(layoutWidget);
        rankbutton->setObjectName(QStringLiteral("rankbutton"));
        rankbutton->setEnabled(true);
        sizePolicy.setHeightForWidth(rankbutton->sizePolicy().hasHeightForWidth());
        rankbutton->setSizePolicy(sizePolicy);
        rankbutton->setFont(font3);
        rankbutton->setCursor(QCursor(Qt::PointingHandCursor));
        rankbutton->setFocusPolicy(Qt::ClickFocus);

        gridLayout->addWidget(rankbutton, 4, 0, 1, 1);

        aboutbutton = new QPushButton(layoutWidget);
        aboutbutton->setObjectName(QStringLiteral("aboutbutton"));
        sizePolicy.setHeightForWidth(aboutbutton->sizePolicy().hasHeightForWidth());
        aboutbutton->setSizePolicy(sizePolicy);
        aboutbutton->setFont(font3);
        aboutbutton->setCursor(QCursor(Qt::PointingHandCursor));
        aboutbutton->setFocusPolicy(Qt::ClickFocus);

        gridLayout->addWidget(aboutbutton, 4, 1, 1, 1);


        horizontalLayout->addLayout(gridLayout);

        WindowClass->setCentralWidget(centralWidget);

        retranslateUi(WindowClass);
        QObject::connect(submitbutton, SIGNAL(clicked()), WindowClass, SLOT(check()));
        QObject::connect(aboutbutton, SIGNAL(clicked()), WindowClass, SLOT(about()));
        QObject::connect(difficultybox, SIGNAL(currentIndexChanged(QString)), WindowClass, SLOT(difficulty(QString)));
        QObject::connect(startbutton, SIGNAL(clicked()), WindowClass, SLOT(start()));
        QObject::connect(modebox, SIGNAL(currentIndexChanged(QString)), WindowClass, SLOT(mode(QString)));

        submitbutton->setDefault(false);


        QMetaObject::connectSlotsByName(WindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *WindowClass)
    {
        WindowClass->setWindowTitle(QApplication::translate("WindowClass", "\346\225\260\347\213\254", nullptr));
        game->setText(QApplication::translate("WindowClass", "\346\270\270\346\210\217", nullptr));
        calculator->setText(QApplication::translate("WindowClass", "\350\256\241\347\256\227\345\231\250", nullptr));
        rules->setText(QApplication::translate("WindowClass", "\350\247\204\345\210\231", nullptr));
        about->setText(QApplication::translate("WindowClass", "\345\205\263\344\272\216", nullptr));
        easy->setText(QApplication::translate("WindowClass", "\347\256\200\345\215\225", nullptr));
        difficult->setText(QApplication::translate("WindowClass", "\345\233\260\351\232\276", nullptr));
        professional->setText(QApplication::translate("WindowClass", "\351\252\250\347\201\260\347\272\247", nullptr));
        label->setText(QApplication::translate("WindowClass", "\346\227\266\351\227\264\357\274\232", nullptr));
        label_3->setText(QApplication::translate("WindowClass", "\346\250\241\345\274\217\357\274\232", nullptr));
        modebox->setItemText(0, QApplication::translate("WindowClass", "game", nullptr));
        modebox->setItemText(1, QApplication::translate("WindowClass", "calculator", nullptr));

        label_2->setText(QApplication::translate("WindowClass", "\351\232\276\345\272\246\357\274\232", nullptr));
        difficultybox->setItemText(0, QApplication::translate("WindowClass", "easy", nullptr));
        difficultybox->setItemText(1, QApplication::translate("WindowClass", "hard", nullptr));
        difficultybox->setItemText(2, QApplication::translate("WindowClass", "professor", nullptr));

        startbutton->setText(QApplication::translate("WindowClass", "\345\274\200\345\247\213", nullptr));
        submitbutton->setText(QApplication::translate("WindowClass", "\346\217\220\344\272\244", nullptr));
        rankbutton->setText(QApplication::translate("WindowClass", "\346\216\222\350\241\214", nullptr));
        aboutbutton->setText(QApplication::translate("WindowClass", "\345\205\263\344\272\216", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WindowClass: public Ui_WindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOW_H
