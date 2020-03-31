#ifndef __MAINWIN_H
#define __MAINWIN_H

#include <gtkmm.h>
#include "store.h"

class Mainwin : public Gtk::Window
{
private:
    Store *store;
    Gtk::Label *data;
    Gtk::Label *msg;

public:
    Mainwin();
    virtual ~Mainwin();

protected:
    void on_quit_click();
    void on_view_peripheral_click();
    void on_view_desktop_click();
    void on_view_order_click();
    void on_view_customer_click();
    void on_insert_peripheral_click();
    void on_insert_desktop_click();
    void on_insert_order_click();
    void on_insert_customer_click();
    void on_about_click();
    std::string get_string(std::string prompt);
    double get_double(std::string prompt);
    void set_data(std::string s);
    void set_msg(std::string s);
};

#endif
