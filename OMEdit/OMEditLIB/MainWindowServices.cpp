#include "MainWindowServices.h"

#include <stdexcept>

MainWindowServices* pInstance = nullptr;

/*!
 * \brief MainWindow::instance
 * Creates an instance of MainWindow. If we already have an instance then just return it.
 * \return
 */
MainWindowServices* MainWindowServices::instance()
{
  if (!pInstance) {
    throw std::runtime_error("Main window not ready yet.");
  }
  return pInstance;
}
