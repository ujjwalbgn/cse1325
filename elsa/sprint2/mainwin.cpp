#include <iostream>
#include <string>
#include "mainwin.h"
#include "entrydialog.h"

// GUI SETUP
Mainwin::Mainwin()
{
    set_default_size(600, 200);
    set_title("ELSA");

    Gtk::Box *vbox = Gtk::manage(new Gtk::VBox);
    add(*vbox);

    //Menu
    Gtk::MenuBar *menubar = Gtk::manage(new Gtk::MenuBar);
    vbox->pack_start(*menubar, Gtk::PACK_SHRINK, 0);

    //FILE
    Gtk::MenuItem *menuitem_file = Gtk::manage(new Gtk::MenuItem("_File", true));
    menubar->append(*menuitem_file);
    Gtk::Menu *filemenu = Gtk::manage(new Gtk::Menu());
    menuitem_file->set_submenu(*filemenu);

    //Quit
    Gtk::MenuItem *menuitem_quit = Gtk::manage(new Gtk::MenuItem("_Quit", true));
    menuitem_quit->signal_activate().connect([this] { this->on_quit_click(); });
    filemenu->append(*menuitem_quit);

    //view
    Gtk::MenuItem *menuitem_view = Gtk::manage(new Gtk::MenuItem("_View", true));
    menubar->append(*menuitem_view);
    Gtk::Menu *viewmenu = Gtk::manage(new Gtk::Menu());
    menuitem_view->set_submenu(*viewmenu);

    //customer
    Gtk::MenuItem *menuitem_customer = Gtk::manage(new Gtk::MenuItem("_customer", true));
    menuitem_customer->signal_activate().connect([this] { this->on_view_customer_click(); });
    viewmenu->append(*menuitem_customer);

    //peripheral
    Gtk::MenuItem *menuitem_peripheral = Gtk::manage(new Gtk::MenuItem("_peripheral", true));
    menuitem_peripheral->signal_activate().connect([this] { this->on_view_peripheral_click(); });
    viewmenu->append(*menuitem_peripheral);

    //desktop
    Gtk::MenuItem *menuitem_desktop = Gtk::manage(new Gtk::MenuItem("_desktop", true));
    menuitem_desktop->signal_activate().connect([this] { this->on_view_desktop_click(); });
    viewmenu->append(*menuitem_desktop);

    //order
    Gtk::MenuItem *menuitem_order = Gtk::manage(new Gtk::MenuItem("_order", true));
    menuitem_order->signal_activate().connect([this] { this->on_view_order_click(); });
    viewmenu->append(*menuitem_order);

    Gtk::MenuItem *menuitem_insert = Gtk::manage(new Gtk::MenuItem("_Insert", true));
    menubar->append(*menuitem_insert);
    Gtk::Menu *insertmenu = Gtk::manage(new Gtk::Menu());
    menuitem_insert->set_submenu(*insertmenu);

    //Customer
    Gtk::MenuItem *menuitem_Customer = Gtk::manage(new Gtk::MenuItem("_Customer", true));
    menuitem_Customer->signal_activate().connect([this] { this->on_insert_customer_click(); });
    insertmenu->append(*menuitem_Customer);

    //Peripheral
    Gtk::MenuItem *menuitem_Peripheral = Gtk::manage(new Gtk::MenuItem("_Peripheral", true));
    menuitem_Peripheral->signal_activate().connect([this] { this->on_insert_peripheral_click(); });
    insertmenu->append(*menuitem_Peripheral);

    //Desktop
    Gtk::MenuItem *menuitem_Desktop = Gtk::manage(new Gtk::MenuItem("_Desktop", true));
    menuitem_Desktop->signal_activate().connect([this] { this->on_insert_desktop_click(); });
    insertmenu->append(*menuitem_Desktop);

    //Order
    Gtk::MenuItem *menuitem_Order = Gtk::manage(new Gtk::MenuItem("_Order", true));
    menuitem_Order->signal_activate().connect([this] { this->on_insert_order_click(); });
    insertmenu->append(*menuitem_Order);

    //Help
    Gtk::MenuItem *menuitem_help = Gtk::manage(new Gtk::MenuItem("_Help", true));
    menubar->append(*menuitem_help);
    Gtk::Menu *helpmenu = Gtk::manage(new Gtk::Menu());
    menuitem_help->set_submenu(*helpmenu);

    data = Gtk::manage(new Gtk::Label());
    data->set_hexpand(true);
    data->set_vexpand(true);
    vbox->add(*data);

    store = new Store;

    msg = Gtk::manage(new Gtk::Label());
    msg->set_hexpand(true);
    vbox->add(*msg);

    vbox->show_all();
}

//Destructor
Mainwin::~Mainwin() {}

//Quit
void Mainwin::on_quit_click()
{
    close();
}

//Help MenuItem
void Mainwin::on_about_click()
{
    Gtk::AboutDialog dialog;
    dialog.set_transient_for(*this); // Avoid the discouraging warning
    dialog.set_program_name("ElSA");
    dialog.set_version("Version 1.2.1");
    dialog.set_copyright("Copyright 2017-2020");
    dialog.set_license_type(Gtk::License::LICENSE_GPL_3_0);
    std::vector<Glib::ustring> authors = {"UjjwalBGN"};
    dialog.set_authors(authors);
    dialog.run();
}

void Mainwin::set_data(std::string s)
{
    data->set_markup(s);
}

void Mainwin::set_msg(std::string s)
{
    msg->set_markup(s);
}

std::string Mainwin::get_string(std::string prompt)
{
    EntryDialog entrydialog1{*this, prompt, true};
    entrydialog1.set_text("Enter Text");
    entrydialog1.run();
    return entrydialog1.get_text();
}

double Mainwin::get_double(std::string prompt)
{
    EntryDialog entrydialog2{*this, prompt, true};
    entrydialog2.set_text("Enter Text");
    entrydialog2.run();
    return std::stod(entrydialog2.get_text());
}

void Mainwin::on_view_peripheral_click()
{
    std::ostringstream oss;
    for (int i = 0; i < store->num_options(); ++i)
    {
        oss << i << ") " << store->option(i) << "\n";
    }
    set_data(oss.str());
}

void Mainwin::on_view_customer_click()
{
    std::ostringstream oss;
    for (int i = 0; i < store->num_customers(); ++i)
    {
        oss << i << ") " << store->customer(i) << "\n";
    }
    set_data(oss.str());
}

void Mainwin::on_view_desktop_click()
{
    std::ostringstream oss;
    for (int i = 0; i < store->num_desktops(); ++i)
        oss << i << ") " << store->desktop(i) << "\n";

    set_data(oss.str());
}

void Mainwin::on_view_order_click()
{
    std::ostringstream oss;
    for (int i = 0; i < store->num_orders(); ++i)
        oss << i << ") " << store->order(i) << "\n";

    set_data(oss.str());
}

void Mainwin::on_insert_peripheral_click()
{
    std::string s;
    s = Mainwin::get_string("Peripheral");
    double cost;
    cost = Mainwin::get_double("Cost");
    Options option{s, cost};
    store->add_option(option);

    set_msg("Peripheral added.");
}

void Mainwin::on_insert_order_click()
{
    int customer = -1;
    int order = -1;
    int desktop = -1;
    try
    {
        for (int i = 0; i < store->num_customers(); ++i)
            std::cout << "\n"
                      << i << ") " << store->customer(i) << '\n';

        customer = (int)Mainwin::get_double("Which customer (-1 when done)?");
        std::cout << store->customer(customer) << '\n';

        order = store->new_order(customer);
        std::cout << "\n"
                  << "Order " << order
                  << " created for Customer " << customer << "\n";
        desktop = 0;
    }
    catch (std::exception &e)
    {
        std::cerr << "#### UNABLE TO CREATE ORDER FOR CUSTOMER "
                  << customer << " ####\n\n";
    }

    while (desktop >= 0)
    {
        for (int i = 0; i < store->num_desktops(); ++i)
            std::cout << "\n"
                      << i << ") " << store->desktop(i) << '\n';
        desktop = (int)get_double("Desktop(-1 when done)?");
        if (desktop == -1)
            break;
        try
        {
            store->add_desktop(desktop, order);
        }
        catch (std::exception &e)
        {
            std::cerr << "#### UNABLE TO ADD DESKTOP " << desktop
                      << " TO ORDER " << order << std::endl;
            desktop = 0;
        }
    }

    if (order >= 0)
        std::cout << "\n++++ Order " << order << " Placed ++++\n"
                  << store->order(order);

    set_msg("Order added.");
}

void Mainwin::on_insert_desktop_click()
{
    int desktop = store->new_desktop();

    while (true)
    {
        std::cout << "\n"
                  << store->desktop(desktop) << "\n\n";
        for (int i = 0; i < store->num_options(); ++i)
            std::cout << i << ") " << store->option(i) << "\n";
        int option;
        option = (int)Mainwin::get_double("\nAdd which peripheral (-1 when done)? ");
        if (option == -1)
            break;
        try
        {
            store->add_option(option, desktop);
        }
        catch (std::exception &e)
        {
            std::cerr << "#### INVALID OPTION ####\n\n";
        }
    }
    set_msg("Desktop Added");
}

void Mainwin::on_insert_customer_click()
{
    std::string name;
    name = Mainwin::get_string("Customer Name");
    std::string phone;
    phone = Mainwin::get_string("Phone");
    std::string email;
    email = Mainwin::get_string("Email");
    Customer customer{name, phone, email};
    store->add_customer(customer);
    //message
    set_msg("Customer Added.");
}
