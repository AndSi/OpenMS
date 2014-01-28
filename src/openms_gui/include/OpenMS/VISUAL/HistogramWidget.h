// --------------------------------------------------------------------------
//                   OpenMS -- Open-Source Mass Spectrometry
// --------------------------------------------------------------------------
// Copyright The OpenMS Team -- Eberhard Karls University Tuebingen,
// ETH Zurich, and Freie Universitaet Berlin 2002-2013.
//
// This software is released under a three-clause BSD license:
//  * Redistributions of source code must retain the above copyright
//    notice, this list of conditions and the following disclaimer.
//  * Redistributions in binary form must reproduce the above copyright
//    notice, this list of conditions and the following disclaimer in the
//    documentation and/or other materials provided with the distribution.
//  * Neither the name of any author or any participating institution
//    may be used to endorse or promote products derived from this software
//    without specific prior written permission.
// For a full list of authors, refer to the file AUTHORS.
// --------------------------------------------------------------------------
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL ANY OF THE AUTHORS OR THE CONTRIBUTING
// INSTITUTIONS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
// EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
// PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
// OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
// WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
// OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
// ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// --------------------------------------------------------------------------
// $Maintainer: Timo Sachsenberg $
// $Authors: Marc Sturm $
// --------------------------------------------------------------------------


#ifndef OPENMS_VISUAL_HISTOGRAMWIDGET_H
#define OPENMS_VISUAL_HISTOGRAMWIDGET_H

// QT
#include <QtGui/QWidget>
#include <QtGui/QPixmap>
class QPaintEvent;
class QResizeEvent;
class QMouseEvent;

//OpenMS
#include <OpenMS/MATH/STATISTICS/Histogram.h>

namespace OpenMS
{
  class AxisWidget;
  class String;

  /**
      @brief Widget which can visualize a histogram.

      @image html HistogramWidget.png

      It can also be used to define a left and right boundary inside the values.
  It supports normal and log scaling via the context menu.

      @ingroup Visual
  */
  class OPENMS_GUI_DLLAPI HistogramWidget :
    public QWidget
  {
    Q_OBJECT

public:
    /// Constructor
    HistogramWidget(const Math::Histogram<> & distribution, QWidget * parent = 0);

    /// Destructor
    virtual ~HistogramWidget();

    /// Returns the value f the lower splitter
    DoubleReal getLeftSplitter();

    /// Returns the value of the upper splitter
    DoubleReal getRightSplitter();

    /// Set axis legends
    void setLegend(const String & legend);

public slots:
    /// Shows the splitters if @p on is true. Hides them otherwise.
    void showSplitters(bool on);

    /// Sets the value of the right splitter
    void setRightSplitter(DoubleReal pos);

    /// Sets the value of the left splitter
    void setLeftSplitter(DoubleReal pos);

    /// Enables/disables log mode
    void setLogMode(bool log_mode);

protected:
    /// The histogram to display
    Math::Histogram<> dist_;

    /// Flag that indicates if splitters are shown
    bool show_splitters_;

    /// Value of the right splitter
    DoubleReal left_splitter_;

    /// Value of the right splitter
    DoubleReal right_splitter_;

    /// The splitter that is currently dragged (0=none, 1=left, 2=right)
    UInt moving_splitter_;

    /// X axis
    AxisWidget * bottom_axis_;

    /// Margin around plot
    UInt margin_;

    /// Internal buffer for the double buffering
    QPixmap buffer_;

    /// Flag that indicates the current mode
    bool log_mode_;

    /// Repaints the contents to the buffer and calls update()
    void invalidate_();

    ///@name reimplemented Qt events
    //@{
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void resizeEvent(QResizeEvent *);
    //@}

protected slots:

    /// Context menu event
    void showContextMenu(const QPoint & pos);
  };
} // namespace OpenMS


#endif