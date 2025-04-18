#include "DrawBoard.h"
#include "ui_DrawBoard.h"
#include<QDebug>
#include<cmath>
#include<QtMath>
#include<QStandardPaths>

MyDrawBoard::MyDrawBoard(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::mainWindow)
{
    ui->setupUi(this);
    initUi();
}

MyDrawBoard::~MyDrawBoard()
{
    delete ui;
   }

//初始化函数
void MyDrawBoard::initUi()
{
       // 连接信号槽（仅在 UI 组件有效时）              
    connect(ui->gvBoard, &BoardGraphicsView::mousepressed, this, &MyDrawBoard::onMousePress);
    connect(ui->gvBoard, &BoardGraphicsView::mousemoved, this, &MyDrawBoard::onMouseMove);
    connect(ui->gvBoard, &BoardGraphicsView::mousereleased, this, &MyDrawBoard::onMouseRelease);
    connect(ui->tbrFile,SIGNAL(actionTriggered(QAction *)),this,SLOT(toolButtonClicked(QAction *)));
    setWindowIcon(QIcon("D:/Work/SUT/FY25/CPlus/MyDrawBoard/image/drawboard.png"));
    setWindowFlag(Qt::WindowType::MSWindowsFixedSizeDialogHint);
    ui->tbrFile->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonIconOnly);
    ui->tbrFile->setIconSize(QSize(51,51));
    ui->tbrFile->layout()->setContentsMargins(5,5,5,5);
    ui->tbrFile->layout()->setSpacing(20);
    tbNew=new QAction(QIcon("D:/Work/SUT/FY25/CPlus/MyDrawBoard/image/new.png"),"新建");
    ui->tbrFile->addAction(tbNew);
    tbOpen=new QAction(QIcon("D:/Work/SUT/FY25/CPlus/MyDrawBoard/image/open.png"),"打开");
    ui->tbrFile->addAction(tbOpen);
    tbSave=new QAction(QIcon("D:/Work/SUT/FY25/CPlus/MyDrawBoard/image/save.png"),"保存");
    ui->tbrFile->addAction(tbSave);
    tbSaveAsPic=new QAction(QIcon("D:/Work/SUT/FY25/CPlus/MyDrawBoard/image/saveother.png"),"另存为");
    ui->tbrFile->addAction(tbSaveAsPic);
    connect(tbSave, &QAction::triggered, this, &MyDrawBoard::saveBoard);
    connect(tbSaveAsPic, &QAction::triggered, this, &MyDrawBoard::saveBoardAsPic);
    //边距和间距
    ui->tbrStyle->layout()->setContentsMargins(5,5,5,5);
    ui->tbrStyle->layout()->setSpacing(10);
    QFont font("仿宋",14);
    //标题 文本标签
    label = new QLabel("样式栏");
    label->setFont(font);
    ui->tbrStyle->addWidget(label);
    ui->tbrStyle->addSeparator();
    //填充色 按钮
    pbBrushColor = new QPushButton();
    pbBrushColor->setAutoFillBackground(true);
    pbBrushColor->setPalette(QPalette(QColor(0,255,0)));
    pbBrushColor->setFixedSize(32,32);
    pbBrushColor->setFlat(true);
    pbBrushColor->setToolTip("填充");
    ui->tbrStyle->addWidget(pbBrushColor);
    ui->tbrStyle->addSeparator();
    connect(pbBrushColor, &QPushButton::clicked, this, &MyDrawBoard::setBrushColor);
    //线宽 下拉列表框
    cobPenWidth = new QComboBox();
    cobPenWidth->addItem(QIcon("D:/Work/SUT/FY25/CPlus/MyDrawBoard/image/zuixi.png"),"");
    cobPenWidth->addItem(QIcon("D:/Work/SUT/FY25/CPlus/MyDrawBoard/image/dierxi.png"),"");
    cobPenWidth->addItem(QIcon("D:/Work/SUT/FY25/CPlus/MyDrawBoard/image/zuicu.png"),"");
    cobPenWidth->setIconSize(QSize(90,32));
    cobPenWidth->setFixedSize(120,32);
    cobPenWidth->setToolTip("线条粗细");
    cobPenWidth->setEditable(false);
    ui->tbrStyle->addWidget(cobPenWidth);
    connect(cobPenWidth,SIGNAL(currentIndexChanged(int)),this,SLOT(setPenWidth()));
    //线形 下拉列表框
    cobPenStyle = new QComboBox();
    cobPenStyle->addItem(QIcon("D:/Work/SUT/FY25/CPlus/MyDrawBoard/image/zhengchangxian.png"),"");
    cobPenStyle->addItem(QIcon("D:/Work/SUT/FY25/CPlus/MyDrawBoard/image/dianxian.png"),"");
    cobPenStyle->addItem(QIcon("D:/Work/SUT/FY25/CPlus/MyDrawBoard/image/dianxianxian.png"),"");
    cobPenStyle->setIconSize(QSize(90,32));
    cobPenStyle->setFixedSize(120,32);
    cobPenStyle->setToolTip("线形");
    cobPenStyle->setEditable(false);
    ui->tbrStyle->addWidget(cobPenStyle);
    connect(cobPenStyle,SIGNAL(currentIndexChanged(int)),this,SLOT(setPenStyle()));
    //线条颜色 按钮
    pbPenColor = new QPushButton();
    pbPenColor->setAutoFillBackground(true);
    pbPenColor->setPalette(QPalette(QColor(0,0,255)));
    pbPenColor->setFixedSize(32,32);
    pbPenColor->setFlat(true);
    pbPenColor->setToolTip("线条颜色");
    pbPenColor->setEnabled(false);
    ui->tbrStyle->addWidget(pbPenColor);
    ui->tbrStyle->addSeparator();
    connect(pbPenColor,SIGNAL(clicked()),this,SLOT(setPenColor()));
    //字体 下拉列表框
    cobFont = new QComboBox();
    cobFont->addItem("Times New Roman");
    cobFont->addItem("微软雅黑");
    cobFont->addItem("华文楷体");
    cobFont->setFont(font);
    cobFont->setFixedSize(180,32);
    cobFont->setToolTip("字体");
    cobFont->setEnabled(false);
    ui->tbrStyle->addWidget(cobFont);
    connect(cobFont,SIGNAL(currentIndexChanged(int)),this,SLOT(setTextFont()));
    //字号 数字选择框
    sbFontSize = new QSpinBox();
    sbFontSize->setMinimum(6);
    sbFontSize->setMaximum(72);
    sbFontSize->setValue(12);
    sbFontSize->setFont(font);
    sbFontSize->setAlignment(Qt::AlignmentFlag::AlignHCenter);
    sbFontSize->setFixedSize(50,32);
    sbFontSize->setToolTip("字号");
    sbFontSize->setEnabled(false);
    ui->tbrStyle->addWidget(sbFontSize);
    connect(sbFontSize,SIGNAL(valueChanged(int)),this,SLOT(setFontSize()));
    //加粗 按钮
    pbBold = new QPushButton();
    pbBold->setIcon(QIcon("D:/Work/SUT/FY25/CPlus/MyDrawBoard/image/jiacu.png"));
    pbBold->setIconSize(QSize(16,16));
    pbBold->setFixedSize(32,32);
    pbBold->setStyleSheet("background-color:whitesmoke");
    pbBold->setToolTip("加粗");
    pbBold->setEnabled(false);
    ui->tbrStyle->addWidget(pbBold);
    connect(pbBold,SIGNAL(clicked()),this,SLOT(setTextBold()));
    //倾斜 按钮
    pbItalic = new QPushButton();
    pbItalic->setIcon(QIcon("D:/Work/SUT/FY25/CPlus/MyDrawBoard/image/xieti.png"));
    pbItalic->setIconSize(QSize(16,16));
    pbItalic->setFixedSize(32,32);
    pbItalic->setStyleSheet("background-color:whitesmoke");
    pbItalic->setToolTip("倾斜");
    pbItalic->setEnabled(false);
    ui->tbrStyle->addWidget(pbItalic);
    connect(pbItalic,SIGNAL(clicked()),this,SLOT(setTextItalic()));
    //文字颜色 按钮
    pbTextColor = new QPushButton();
    pbTextColor->setAutoFillBackground(true);
    pbTextColor->setPalette(QPalette(QColor(0,0,0)));
    pbTextColor->setFixedSize(32,32);
    pbTextColor->setFlat(true);
    pbTextColor->setToolTip("文字颜色");
    pbTextColor->setEnabled(false);
    ui->tbrStyle->addWidget(pbTextColor);
    ui->tbrStyle->addSeparator();
    connect(pbTextColor,SIGNAL(clicked()),this,SLOT(setTextColor()));
    //放大图元 按钮
    pbZoomIn=new QPushButton();
    pbZoomIn->setIcon(QIcon("D:/Work/SUT/FY25/CPlus/MyDrawBoard/image/bigger.png"));
    pbZoomIn->setIconSize(QSize(16,16));
    pbZoomIn->setFixedSize(32,32);
    pbZoomIn->setStyleSheet("background-color:whitesmoke");
    pbZoomIn->setToolTip("放大");
    ui->tbrStyle->addWidget(pbZoomIn);
    connect(pbZoomIn,SIGNAL(clicked()),this,SLOT(onZoomIn()));
    //缩小图元 按钮
    pbZoomOut = new QPushButton();
    pbZoomOut->setIcon(QIcon("D:/Work/SUT/FY25/CPlus/MyDrawBoard/image/smaller.png"));
    pbZoomOut->setIconSize(QSize(16,16));
    pbZoomOut->setFixedSize(32,32);
    pbZoomOut->setStyleSheet("background-color:whitesmoke");
    pbZoomOut->setToolTip("缩小");
    ui->tbrStyle->addWidget(pbZoomOut);
    connect(pbZoomOut,SIGNAL(clicked()),this,SLOT(onZoomOut()));
    //左旋图元 按钮
    pbRotateLeft = new QPushButton();
    pbRotateLeft->setIcon(QIcon("D:/Work/SUT/FY25/CPlus/MyDrawBoard/image/turnleft.png"));
    pbRotateLeft->setIconSize(QSize(16,16));
    pbRotateLeft->setFixedSize(32,32);
    pbRotateLeft->setStyleSheet("background-color:whitesmoke");
    pbRotateLeft->setToolTip("左旋");
    ui->tbrStyle->addWidget(pbRotateLeft);
    connect(pbRotateLeft,SIGNAL(clicked()),this,SLOT(onRotateLeft()));
    //右旋图元 按钮
    pbRotateRight = new QPushButton();
    pbRotateRight->setIcon(QIcon("D:/Work/SUT/FY25/CPlus/MyDrawBoard/image/turnright.png"));
    pbRotateRight->setIconSize(QSize(16,16));
    pbRotateRight->setFixedSize(32,32);
    pbRotateRight->setStyleSheet("background-color:whitesmoke");
    pbRotateRight->setToolTip("右旋");
    ui->tbrStyle->addWidget(pbRotateRight);
    connect(pbRotateRight,SIGNAL(clicked()),this,SLOT(onRotateRight()));
    //删除图元 按钮
    pbDelete = new QPushButton();
    pbDelete->setIcon(QIcon("D:/Work/SUT/FY25/CPlus/MyDrawBoard/image/delete.png"));
    pbDelete->setIconSize(QSize(16,16));
    pbDelete->setFixedSize(32,32);
    pbDelete->setStyleSheet("background-color:whitesmoke");
    pbDelete->setToolTip("删除");
    ui->tbrStyle->addWidget(pbDelete);
    connect(pbDelete,SIGNAL(clicked()),this,SLOT(onDelete()));
    //工具箱按钮
    ui->tbrShape->layout()->setContentsMargins(10,10,10,10);
    ui->tbrShape->layout()->setSpacing(20);
    //圆形 按钮
    pbEllipse = new ShapeButton();
    pbEllipse->setIcon(QIcon("D:/Work/SUT/FY25/CPlus/MyDrawBoard/image/round.png"));
    pbEllipse->setIconSize(QSize(51,51));
    pbEllipse->setStyleSheet("background-color:whitesmoke");
    ui->tbrShape->addWidget(pbEllipse);
    connect(pbEllipse, &QPushButton::released, this, &MyDrawBoard::drawEllipse);
    //矩形 按钮
    pbRect = new ShapeButton();
    pbRect->setIcon(QIcon("D:/Work/SUT/FY25/CPlus/MyDrawBoard/image/juxing.png"));
    pbRect->setIconSize(QSize(51,51));
    pbRect->setStyleSheet("background-color:whitesmoke");
    ui->tbrShape->addWidget(pbRect);
    connect(pbRect, &QPushButton::released, this, &MyDrawBoard::drawRect);
    //直线 按钮
    pbLine = new ShapeButton();
    pbLine->setIcon(QIcon("D:/Work/SUT/FY25/CPlus/MyDrawBoard/image/zhixian.png"));
    pbLine->setIconSize(QSize(51,51));
    pbLine->setStyleSheet("background-color:whitesmoke");
    ui->tbrShape->addWidget(pbLine);
    connect(pbLine, &QPushButton::released, this, &MyDrawBoard::drawLine);
    //文字 按钮
    pbText = new ShapeButton();
    pbText->setIcon(QIcon("D:/Work/SUT/FY25/CPlus/MyDrawBoard/image/wenzi.png"));
    pbText->setIconSize(QSize(51,51));
    pbText->setStyleSheet("background-color:whitesmoke");
    pbText->setToolTip("添加文字");
    ui->tbrShape->addWidget(pbText);
    connect(pbText, &QPushButton::released, this, &MyDrawBoard::drawText);
    //创建绘图区
    ui->gvBoard->setGeometry(0,0,1000,600);
    ui->gvBoard->setMouseTracking(true);//开启鼠标跟踪
    float w = ui->gvBoard->width() - 2;
    float h = ui->gvBoard->height() - 2;
    QRectF rect = QRectF(-(w/2),-(h/2),w,h);
    scene = new BoardGraphicsScene();
    scene->setSceneRect(rect);
    ui->gvBoard->setScene(scene);
    lbStatus = new QLabel();
    lbStatus->setText("图元文件"+Global::currentFileName);
    ui->statusbar->addPermanentWidget(lbStatus);
    connect(ui->gvBoard,SIGNAL(mousemoved(QPoint)),this,SLOT(updateStatus(QPoint)));
    item = nullptr;
 }

//公共函数实现区
void MyDrawBoard::getZIndex(QGraphicsItem *item)//根据Z值决定新图元的位置一直在旧图元之上
{
    item->setZValue(Global::zIndex);
    Global::zIndex+=1;
}

void MyDrawBoard::addItemToScene(QGraphicsItem *item)
{
    item->setFlag(QGraphicsItem::GraphicsItemFlag::ItemIsSelectable);
    item->setFlag(QGraphicsItem::GraphicsItemFlag::ItemIsFocusable);
    item->setFlag(QGraphicsItem::GraphicsItemFlag::ItemIsMovable);
    scene->addItem(item);

}

void MyDrawBoard::updateTbrStyle()
{
    if(item == nullptr)
    {
        pbBrushColor->setPalette(QPalette(QColor(0,255,0)));
        pbBrushColor->setEnabled(false);
        cobPenWidth->setCurrentIndex(0);
        cobPenWidth->setEnabled(false);
        cobPenStyle->setCurrentIndex(0);
        cobPenStyle->setEnabled(false);
        pbPenColor->setPalette(QPalette(QColor(0,0,255)));
        pbPenColor->setEnabled(false);
        cobFont->setCurrentIndex(0);
        cobFont->setEnabled(false);
        sbFontSize->setValue(12);
        sbFontSize->setEnabled(false);
        pbBold->setFlat(false);
        pbBold->setStyleSheet("background-color:whitesmoke");
        pbBold->setEnabled(false);
        pbItalic->setFlat(false);
        pbItalic->setStyleSheet("background-color:whitesmoke");
        pbItalic->setEnabled(false);
        pbTextColor->setPalette(QPalette(QColor(0,0,0)));
        pbTextColor->setEnabled(false);
        return;
    }
    if(item->type() == QGraphicsEllipseItem::Type || item->type() == QGraphicsRectItem::Type || item->type() == QGraphicsLineItem::Type)
    {
        if(item->type() == QGraphicsEllipseItem::Type)
        {
            QGraphicsEllipseItem *curItem = qgraphicsitem_cast<QGraphicsEllipseItem *>(item);
            pbBrushColor->setEnabled(true);
            pbBrushColor->setPalette(QPalette(curItem->brush().color()));//调色板
            cobPenWidth->setEnabled(true);
            cobPenWidth->setCurrentIndex(int(curItem->pen().width()/2)-1);//下拉列表框
            cobPenStyle->setEnabled(true);
            cobPenStyle->setCurrentIndex(int((curItem->pen().style()-1)/2));
            pbPenColor->setEnabled(true);
            pbPenColor->setPalette(QPalette(curItem->pen().color()));
        }else if(item->type() == QGraphicsRectItem::Type)
        {
            QGraphicsRectItem *curItem = qgraphicsitem_cast<QGraphicsRectItem *>(item);
            pbBrushColor->setEnabled(true);
            pbBrushColor->setPalette(QPalette(curItem->brush().color()));//调色板
            cobPenWidth->setEnabled(true);
            cobPenWidth->setCurrentIndex(int(curItem->pen().width()/2)-1);//下拉列表框
            cobPenStyle->setEnabled(true);
            cobPenStyle->setCurrentIndex(int((curItem->pen().style()-1)/2));
            pbPenColor->setEnabled(true);
            pbPenColor->setPalette(QPalette(curItem->pen().color()));
        }else
        {
            QGraphicsLineItem *curItem = qgraphicsitem_cast<QGraphicsLineItem *>(item);
            pbBrushColor->setPalette(QPalette(QColor(0,255,0)));
            pbBrushColor->setEnabled(false);
            cobPenWidth->setEnabled(true);
            cobPenWidth->setCurrentIndex(int(curItem->pen().width()/2)-1);//下拉列表框
            cobPenStyle->setEnabled(true);
            cobPenStyle->setCurrentIndex(int((curItem->pen().style()-1)/2));
            pbPenColor->setEnabled(true);
            pbPenColor->setPalette(QPalette(curItem->pen().color()));
        }
        cobFont->setCurrentIndex(0);
        cobFont->setEnabled(false);
        sbFontSize->setValue(12);
        sbFontSize->setEnabled(false);
        pbBold->setFlat(false);
        pbBold->setStyleSheet("background-color:whitesmoke");
        pbBold->setEnabled(false);
        pbItalic->setFlat(false);
        pbItalic->setStyleSheet("background-color:whitesmoke");
        pbItalic->setEnabled(false);
        pbTextColor->setPalette(QPalette(QColor(0,0,0)));
        pbTextColor->setEnabled(false);
    }else if(item->type() == QGraphicsTextItem::Type)
    {
        QGraphicsTextItem *curItem = qgraphicsitem_cast<QGraphicsTextItem *>(item);
        cobFont->setEnabled(true);
        cobFont->setCurrentText(curItem->font().family());
        sbFontSize->setEnabled(true);
        sbFontSize->setValue(curItem->font().pointSize());
        pbBold->setEnabled(true);
        if(curItem->font().bold())
        {
            pbBold->setFlat(true);
            pbBold->setStyleSheet("background-color: whitesmoke; border :1px solid black");
        }else
        {
            pbBold->setFlat(false);
            pbBold->setStyleSheet("background-color: whitesmoke;");
        }
        pbItalic->setEnabled(true);
        if(curItem->font().italic())
        {
            pbItalic->setFlat(true);
            pbItalic->setStyleSheet("background-color:whitesmoke;border:1px solid black");
        }else
        {
            pbItalic->setFlat(false);
            pbItalic->setStyleSheet("background-color:whitesmoke");
        }
        pbTextColor->setEnabled(true);
        pbTextColor->setPalette(QPalette(curItem->defaultTextColor()));//获取默认文本颜色
        pbBrushColor->setPalette(QPalette(QColor(0,255,0)));
        pbBrushColor->setEnabled(false);
        cobPenWidth->setCurrentIndex(0);
        cobPenWidth->setEnabled(false);
        cobPenStyle->setCurrentIndex(0);
        cobPenStyle->setEnabled(false);
        pbPenColor->setPalette(QPalette(QColor(0,0,255)));
        pbPenColor->setEnabled(false);
    }
}

void MyDrawBoard::clearScene()
{
    foreach(QGraphicsItem *graphItem,scene->items())//遍历场景中所有图元
        scene->removeItem(graphItem);
}

void MyDrawBoard::loadBoard()
{
    QString filePath = QFileDialog::getOpenFileName(this, "打开文件", "", "图形文件 (*.graph);;所有文件 (*.*)");
       if (filePath.isEmpty()) return;

       QFile file(filePath);
       if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
           QMessageBox::warning(this, "错误", "无法打开文件！");
           return;
       }

       QTextStream in(&file);
       clearScene(); // 清空当前场景

       while (!in.atEnd()) {
           QString line = in.readLine();
           QStringList parts = line.split(",");
           if (parts.size() == 11) {
               QString type = parts[0];
               QPointF pos(parts[1].toDouble(), parts[2].toDouble());
               qreal width = parts[3].toDouble();
               qreal height = parts[4].toDouble();
               int penWidth = parts[5].toInt();
               Qt::PenStyle penStyle = static_cast<Qt::PenStyle>(parts[6].toInt());
               QColor penColor(parts[7].toInt(), parts[8].toInt(), parts[9].toInt());
               QColor brushColor;
               qreal scale = 1.0;
               qreal rotation = 0.0;
               qreal zValue = parts[10].toDouble();

               // 这里需要根据 type 创建对应的图形项并添加到场景中
               // 示例代码，需要根据实际的图形创建逻辑修改
               if (type == "ellipse") {
                   // 创建椭圆项并设置属性
                   QGraphicsEllipseItem *ellipse = new QGraphicsEllipseItem(pos.x(), pos.y(), width, height);
                   QPen pen(penColor, penWidth, penStyle);
                   ellipse->setPen(pen);
                   ellipse->setBrush(brushColor);
                   ellipse->setScale(scale);
                   ellipse->setRotation(rotation);
                   ellipse->setZValue(zValue);
                   addItemToScene(ellipse);
               } else if (type == "rect") {
                   // 创建矩形项并设置属性
                   QGraphicsRectItem *rect = new QGraphicsRectItem(pos.x(), pos.y(), width, height);
                   QPen pen(penColor, penWidth, penStyle);
                   rect->setPen(pen);
                   rect->setBrush(brushColor);
                   rect->setScale(scale);
                   rect->setRotation(rotation);
                   rect->setZValue(zValue);
                   addItemToScene(rect);
               }
               // 可以继续添加其他图形类型的处理逻辑
           }
       }

       file.close();
       Global::currentFileName = filePath;
}

bool MyDrawBoard::saveBoard()
{
    if (Global::currentFileName.isEmpty()) {
        return saveBoardAsPic(); // 如果没有当前文件名，调用另存为功能
    }

    QFile file(Global::currentFileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "错误", "无法保存文件！");
        return false;
    }

    QTextStream out(&file);
    QList<QGraphicsItem *> items = scene->items();
    for (QGraphicsItem *item : items) {
        QString type;
        QPen pen;
        QBrush brush;
        if (auto ellipseItem = dynamic_cast<QGraphicsEllipseItem *>(item)) {
            type = "ellipse";
            pen = ellipseItem->pen();
            brush = ellipseItem->brush();
        } else if (auto rectItem = dynamic_cast<QGraphicsRectItem *>(item)) {
            type = "rect";
            pen = rectItem->pen();
            brush = rectItem->brush();
        } else if (auto lineItem = dynamic_cast<QGraphicsLineItem *>(item)) {
            type = "line";
            pen = lineItem->pen();
            // 直线没有填充，这里可以根据需要处理
            brush = QBrush();
        }
        // 可以继续添加其他图形类型的判断

        if (!type.isEmpty()) {
            QRectF rect = item->boundingRect();
            qreal scale = item->scale();
            qreal rotation = item->rotation();
            qreal zValue = item->zValue();

            out << type << ","
                << rect.x() << "," << rect.y() << ","
                << rect.width() << "," << rect.height() << ","
                << pen.width() << "," << static_cast<int>(pen.style()) << ","
                << pen.color().red() << "," << pen.color().green() << "," << pen.color().blue() << ","
                << zValue << "\n";
        }
    }

    file.close();
    return true;
}
bool MyDrawBoard::saveBoardAsPic()
{
    QString defaultPath = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation);
    QString filePath = QFileDialog::getSaveFileName(this, "另存为", defaultPath, "图片文件 (*.png *.jpg *.bmp);;所有文件 (*.*)");
    if (filePath.isEmpty()) {
        qDebug() << "用户取消了保存操作或者路径为空";
        return false;
    }
    qDebug() << "选择的保存路径: " << filePath;

    // 获取场景的矩形区域
    QRectF sceneRect = scene->sceneRect();
    qDebug() << "场景矩形区域: " << sceneRect;

    if (scene->items().isEmpty()) {
        qDebug() << "场景中没有图形项";
        return false;
    }

    // 创建一个与场景大小相同的 QImage
    QImage image(sceneRect.size().toSize(), QImage::Format_ARGB32);
    image.fill(Qt::transparent);
    // 创建一个 QPainter 用于绘制场景到 QImage 上
    QPainter painter(&image);
    // 在 QImage 上绘制场景
    scene->render(&painter);
    painter.end();
    // 将 QImage 保存为文件
    bool saved = image.save(filePath);
    if (!saved) {
        qDebug() << "保存图片失败: " << filePath;
    }
    return saved;
}

//槽函数实现区
void MyDrawBoard::toolButtonClicked(QAction *tb)
{
    if(tb->text() == "新建")
    {
        if(scene->items().count()!=0)
        {
            int reply = QMessageBox::question(this,"提示","保存更改到"+Global::currentFileName + "吗？",QMessageBox::StandardButton::Discard | QMessageBox::StandardButton::Cancel);
            if(reply == QMessageBox::StandardButton::Save)
            {
                if(saveBoard())
                {
                    clearScene();
                    Global::currentFileName = "graph0";
                }
            }else if(reply == QMessageBox::StandardButton::Discard)
            {
               clearScene();
               Global::currentFileName = "graph0";
            }
        }

    }else if(tb->text() == "打开")
    {
        loadBoard();
    }else if(tb->text() == "保存")
    {
        if(saveBoard())
        {
            QMessageBox::information(this,"提示","已写入二进制文件。");
        }
    }else if(tb->text() == "另存为图片")
       {
        if(saveBoardAsPic())
            QMessageBox::information(this,"提示","已保存为图片。");
    }
}

void MyDrawBoard::setBrushColor()
{
    if(item->type() == QGraphicsEllipseItem::Type)
    {
        QGraphicsEllipseItem *curItem = qgraphicsitem_cast<QGraphicsEllipseItem *>(item);
        QBrush brush = curItem->brush();
        QColor color = brush.color();
        color = QColorDialog::getColor(color,this,"选择填充颜色");
        if(color.isValid())
        {
            brush.setColor(color);
            curItem->setBrush(brush);
            updateTbrStyle();
        }
    }else if(item->type() == QGraphicsRectItem::Type)
    {
        QGraphicsRectItem *curItem = qgraphicsitem_cast<QGraphicsRectItem *>(item);
        QBrush brush = curItem->brush();
        QColor color = brush.color();
        color = QColorDialog::getColor(color,this,"选择填充颜色");
        if(color.isValid())
        {
            brush.setColor(color);
            curItem->setBrush(brush);
            updateTbrStyle();
        }
    }

}

void MyDrawBoard::setPenWidth()
{
    if(item->type() == QGraphicsItem::Type)
    {
        QGraphicsEllipseItem *curItem = qgraphicsitem_cast<QGraphicsEllipseItem *>(item);
        QPen pen = curItem->pen();
        int index = cobPenWidth->currentIndex();
        if(index == 0)
        {
            pen.setWidth(2);
        }else if(index == 1)
        {
            pen.setWidth(4);
        }else if(index == 2)
        {
            pen.setWidth(6);
        }
        curItem->setPen(pen);
        updateTbrStyle();
    }else if(item->type() == QGraphicsRectItem::Type)
    {
        QGraphicsRectItem *curItem = qgraphicsitem_cast<QGraphicsRectItem *>(item);
        QPen pen = curItem->pen();
        int index = cobPenWidth->currentIndex();
        if(index == 0)
        {
            pen.setWidth(2);
        }else if(index == 1)
        {
            pen.setWidth(4);
        }else if(index == 2)
        {
            pen.setWidth(6);
        }
        curItem->setPen(pen);
        updateTbrStyle();
    }else if(item->type() == QGraphicsLineItem::Type)
    {
        QGraphicsLineItem *curItem = qgraphicsitem_cast<QGraphicsLineItem *>(item);
        QPen pen = curItem->pen();
        int index = cobPenWidth->currentIndex();
        if(index == 0)
        {
            pen.setWidth(2);
        }else if(index == 1)
        {
            pen.setWidth(4);
        }else if(index == 2)
        {
            pen.setWidth(6);
        }
        curItem->setPen(pen);
        updateTbrStyle();
    }

}

void MyDrawBoard::setPenColor()
{
    if(item->type() == QGraphicsEllipseItem::Type)
    {
        QGraphicsEllipseItem *curItem =qgraphicsitem_cast<QGraphicsEllipseItem *>(item);
        QPen pen = curItem->pen();
        QColor color = pen.color();
        color = QColorDialog::getColor(color,this,"选择线条颜色");
        if(color.isValid())
        {
            pen.setColor(color);
            curItem->setPen(pen);
            updateTbrStyle();
        }
    }else if(item->type() == QGraphicsRectItem::Type)
    {
        QGraphicsRectItem *curItem = qgraphicsitem_cast<QGraphicsRectItem *>(item);
        QPen pen = curItem->pen();
        QColor color = pen.color();
        color = QColorDialog::getColor(color,this,"选择线条颜色");
        if(color.isValid())
        {
            pen.setColor(color);
            curItem->setPen(pen);
            updateTbrStyle();
        }
    }else if(item->type() == QGraphicsLineItem::Type)
    {
        QGraphicsLineItem *curItem = qgraphicsitem_cast<QGraphicsLineItem *>(item);
        QPen pen = curItem->pen();
        QColor color = pen.color();
        color = QColorDialog::getColor(color,this,"选择线条颜色");
        if(color.isValid())
        {
            pen.setColor(color);
            curItem->setPen(pen);
            updateTbrStyle();
        }
    }

}

void MyDrawBoard::setPenStyle()
{
    if(item->type() == QGraphicsEllipseItem::Type)
    {
        QGraphicsEllipseItem *curItem = qgraphicsitem_cast<QGraphicsEllipseItem *>(item);
        QPen pen = curItem->pen();
        int index = cobPenStyle->currentIndex();
        if(index == 0)
        {
            pen.setStyle(Qt::PenStyle::SolidLine);
        }else if(index == 1)
        {
            pen.setStyle(Qt::PenStyle::DotLine);
        }else if(index == 2)
        {
            pen.setStyle(Qt::PenStyle::DashDotDotLine);
        }
        curItem->setPen(pen);
        updateTbrStyle();
    }else if(item->type() == QGraphicsRectItem::Type)
    {
        QGraphicsRectItem *curItem = qgraphicsitem_cast<QGraphicsRectItem *>(item);
        QPen pen = curItem->pen();
        int index = cobPenStyle->currentIndex();
        if(index == 0)
        {
            pen.setStyle(Qt::PenStyle::SolidLine);
        }else if(index == 1)
        {
            pen.setStyle(Qt::PenStyle::DotLine);
        }else if(index == 2)
        {
            pen.setStyle(Qt::PenStyle::DashDotDotLine);
        }
        curItem->setPen(pen);
        updateTbrStyle();
    }else if(item->type() == QGraphicsLineItem::Type)
    {
        QGraphicsLineItem *curItem = qgraphicsitem_cast<QGraphicsLineItem *>(item);
        QPen pen = curItem->pen();
        int index = cobPenStyle->currentIndex();
        if(index == 0)
        {
            pen.setStyle(Qt::PenStyle::SolidLine);
        }else if(index == 1)
        {
            pen.setStyle(Qt::PenStyle::DotLine);
        }else if(index == 2)
        {
            pen.setStyle(Qt::PenStyle::DashDotDotLine);
        }
        curItem->setPen(pen);
        updateTbrStyle();
    }

}

void MyDrawBoard::setTextFont()
{
    if(item->type() == QGraphicsTextItem::Type)
    {
        QGraphicsTextItem *curItem = qgraphicsitem_cast<QGraphicsTextItem *>(item);
        QFont font = curItem->font();
        font.setFamily(cobFont->currentText());
        curItem->setFont(font);
        updateTbrStyle();
    }

}

void MyDrawBoard::setFontSize()
{
    if(item->type() == QGraphicsTextItem::Type)
    {
        QGraphicsTextItem *curItem = qgraphicsitem_cast<QGraphicsTextItem *>(item);
        QFont font = curItem->font();
        font.setPointSize(sbFontSize->value());
        curItem->setFont(font);
        updateTbrStyle();
    }

}

void MyDrawBoard::setTextBold()
{
    if(item->type() == QGraphicsTextItem::Type)
    {
        QGraphicsTextItem *curItem = qgraphicsitem_cast<QGraphicsTextItem *>(item);
        QFont font = curItem->font();
        if(font.bold()==false)
        {
            font.setBold(true);
            pbBold->setFlat(true);
            pbBold->setStyleSheet("background-color:whitesmoke; border:1px solid black");
        }else
        {
            font.setBold(false);
            pbBold->setFlat(false);
            pbBold->setStyleSheet("background-color:whitesmoke");
        }
        curItem->setFont(font);
        updateTbrStyle();
    }

}

void MyDrawBoard::setTextItalic()
{
    if(item->type() == QGraphicsTextItem::Type)
    {
        QGraphicsTextItem *curItem = qgraphicsitem_cast<QGraphicsTextItem *>(item);
        QFont font = curItem->font();
        if(font.italic() == false)
        {
            font.setItalic(true);
            pbItalic->setFlat(true);
            pbItalic->setStyleSheet("background-color:whitesmoke;border:1px solid black");
        }else
        {
            font.setItalic(false);
            pbItalic->setFlat(false);
            pbItalic->setStyleSheet("background-color:whitesmoke");
        }
        curItem->setFont(font);
        updateTbrStyle();
    }

}

void MyDrawBoard::setTextColor()
{
    if(item->type() == QGraphicsTextItem::Type)
    {
        QGraphicsTextItem *curItem = qgraphicsitem_cast<QGraphicsTextItem *>(item);
        QColor color = curItem->defaultTextColor();
        color = QColorDialog::getColor(color,this,"选择文字颜色");
        if(color.isValid())
        {
            curItem->setDefaultTextColor(color);
            updateTbrStyle();
        }
    }

}

void MyDrawBoard::onZoomIn()
{
    if(item != nullptr)
    {
        item->setScale(item->scale()+0.1);
    }
}

void MyDrawBoard::onZoomOut()
{
    if(item != nullptr)
    {
        item->setScale(item->scale()-0.1);
    }

}

void MyDrawBoard::onRotateLeft()
{
    if(item != nullptr)
    {
        item->setRotation(item->rotation()-10);
    }

}

void MyDrawBoard::onRotateRight()
{
    if(item != nullptr)
    {
        item->setRotation(item->rotation()+10);
    }

}

void MyDrawBoard::onDelete()
{
    if(item != nullptr)
    {
        scene->removeItem(item);
    }

}

void MyDrawBoard::drawEllipse()
{
    QGraphicsEllipseItem *curItem = new QGraphicsEllipseItem(-40,-40,80,80);
    item = curItem;
    QPointF point = ui->gvBoard->mapToScene(Global::pointDragEnter.toPoint());
    curItem->setPos(point);
    QPen *pen = new QPen();
    pen->setWidth(2);
    pen->setColor(Qt::GlobalColor::blue);
    curItem->setPen(*pen);
    curItem->setBrush(QBrush(Qt::GlobalColor::green));
    getZIndex(curItem);
    addItemToScene(curItem);
}

void MyDrawBoard::drawRect()
{
    QGraphicsRectItem *curItem = new QGraphicsRectItem(-30,-30,60,60);
    item = curItem;
    QPointF point = ui->gvBoard->mapToScene(Global::pointDragEnter.toPoint());
    curItem->setPos(point);
    QPen *pen = new QPen();
    pen->setWidth(2);
    pen->setColor(Qt::GlobalColor::blue);
    curItem->setPen(*pen);
    curItem->setBrush(QBrush(Qt::GlobalColor::green));
    getZIndex(curItem);
    addItemToScene(curItem);
}

void MyDrawBoard::drawLine()
{
    QGraphicsLineItem*curItem = new QGraphicsLineItem(-100,0,100,0);
    item = curItem;
    QPointF point = ui->gvBoard->mapToScene(Global::pointDragEnter.toPoint());
    curItem->setPos(point);
    QPen *pen = new QPen();
    pen->setWidth(2);
    pen->setColor(Qt::GlobalColor::blue);
    curItem->setPen(*pen);
    getZIndex(curItem);
    addItemToScene(curItem);
}

void MyDrawBoard::drawText()
{
    bool ok = false;
    QString text = QInputDialog::getText(this,"添加文字","请输入",QLineEdit::Normal,"",&ok);
    if(!ok) return;
    QGraphicsTextItem *curItem = new QGraphicsTextItem(text);
    item = curItem;
    QPointF point = ui->gvBoard->mapToScene(Global::pointDragEnter.toPoint());
    curItem->setPos(point);
    QFont font("Times New Roman",12);
    curItem->setFont(font);
    curItem->setDefaultTextColor(Qt::GlobalColor::black);
    getZIndex(curItem);
    addItemToScene(curItem);


}

void MyDrawBoard::updateStatus(QPoint point)
{
    QPoint sp = ui->gvBoard->mapToScene(point).toPoint();
    ui->statusbar->showMessage("场景坐标(X:"+QString::number(sp.x())+",Y:"+QString::number(sp.y())+")");
    lbStatus->setText("图元文件"+Global::currentFileName);
}

void MyDrawBoard::onMousePress(QPoint point)
{
    QPointF sp = ui->gvBoard->mapToScene(point);
    item = scene->itemAt(sp,ui->gvBoard->transform());
    updateTbrStyle();
    if(item!=nullptr)
    {
        QPointF ip = item->mapFromScene(sp);
        if(item->type() == QGraphicsEllipseItem::Type)
        {
            float d = sqrt(qPow(ip.x(),2)+qPow(ip.y(),2));
            if(d>=(item->boundingRect().width()/2)*0.9)
            {
                Global::resizeDragging = true;
            }
        }else if(item->type() == QGraphicsRectItem::Type)
        {
            if((fabs(ip.x())>=(item->boundingRect().width()/2)*0.8)&&(fabs(ip.y())>=(item->boundingRect().height()/2)*0.8))
            {
                Global::resizeDragging = true;
            }
        }else if(item->type() == QGraphicsLineItem::Type)
        {
            float d = sqrt(qPow(ip.x(),2)+qPow(ip.y(),2));
            if(d>=(item->boundingRect().width()/2)*0.9)
            {
                Global::resizeDragging = true;
            }
        }
    }

}

void MyDrawBoard::onMouseMove(QPoint point)
{
    if(Global::resizeDragging)
    {
        scene->removeItem(item);
        repaintItem(point);
    }

}

void MyDrawBoard::onMouseRelease()
{
    Global::resizeDragging = false;
}

void MyDrawBoard::repaintItem(QPoint point)
{
    if (!item) return;
    QPointF sp  = ui->gvBoard->mapToScene(point);
    QPointF ip = item->mapFromScene(sp);
    QPointF op =item->mapToScene(QPointF(0.0,0.0));
    if(item->type() == QGraphicsEllipseItem::Type)
    {
        QGraphicsEllipseItem *curItem = qgraphicsitem_cast<QGraphicsEllipseItem*>(item);//cast类型转换函数
        int pw = curItem->pen().width();
        Qt::PenStyle ps = curItem->pen().style();
        QColor pc = curItem->pen().color();
        QColor bc = curItem->brush().color();
        float d = sqrt(qPow(ip.x(),2)+qPow(ip.y(),2));
        curItem = new QGraphicsEllipseItem(-d,-d,2*d,2*d);
        QPen pen = QPen();
        pen.setWidth(pw);
        pen.setStyle(ps);
        pen.setColor(pc);
        curItem->setPen(pen);
        curItem->setBrush(QBrush(bc));
        curItem->setPos(op);
        item = curItem;
    }else if(item->type() == QGraphicsRectItem::Type)
    {
        QGraphicsRectItem *curItem = qgraphicsitem_cast<QGraphicsRectItem *>(item);
        int pw = curItem->pen().width();
        Qt::PenStyle ps = curItem->pen().style();
        QColor pc = curItem->pen().color();
        QColor bc = curItem->brush().color();
        float w = abs(ip.x())*2;
        float h = abs(ip.y())*2;
        curItem = new QGraphicsRectItem(-(w/2),-(h/2),w,h);
        QPen pen = QPen();
        pen.setWidth(pw);
        pen.setStyle(ps);
        pen.setColor(pc);
        curItem->setPen(pen);
        curItem->setBrush(QBrush(bc));
        curItem->setPos(op);
        item = curItem;
    }else if(item->type() == QGraphicsLineItem::Type)
    {
        QGraphicsLineItem *curItem = qgraphicsitem_cast<QGraphicsLineItem *>(item);
        int pw = curItem->pen().width();
        Qt::PenStyle ps = curItem->pen().style();
        QColor pc = curItem->pen().color();
        curItem = new QGraphicsLineItem(ip.x(),ip.y(),100,0);
        QPen pen = QPen();
        pen.setWidth(pw);
        pen.setStyle(ps);
        pen.setColor(pc);
        curItem->setPen(pen);
        curItem->setPos(op);
        item = curItem;
    }
    addItemToScene(item);
}

























