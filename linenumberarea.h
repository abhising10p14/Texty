#ifndef LINENUMBERAREA_H
#define LINENUMBERAREA_H


#include<QTextEdit>
namespace Ui {
class LineNumberArea ;
}

class LineNumberArea : public QWidget
{
    Q_OBJECT

public:
    LineNumberArea(QTextEdit *editor);

    QSize sizeHint() const;

protected:
    void paintEvent(QPaintEvent *event);

private:
    QTextEdit *codeEditor;
};
#endif // LINENUMBERAREA_H
