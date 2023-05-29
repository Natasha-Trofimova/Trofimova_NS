#include "menu.h"

void interface () {
    cout << "Menu: " << endl
        << "1. Задать координаты объекта (создать)." << endl
        << "2. Случайно переместить объект." << endl
        << "3. Вывести текущую позицию объекта." << endl
        << "4. Вывести весь пройденный путь." << endl
        << "5. Вывести меню." << endl
        << "6. Выйти." << endl;
}

int show_menu() {
    int ch, obj_x, obj_y, menu_ch;
    Object* dot1 = new Object (0, 0);
    UserEquipment* bag = new UserEquipment(0, 0);
    interface();
    while (1) {
        cin >> ch;
        switch (ch) {
        case 1:
        {
            cout << "Класс объекта?" << endl
            << "1. Object." << endl
            << "2. UserEquipment." << endl;
            cin >> menu_ch;
            switch (menu_ch) {
            case 1:
            {
                cout << "Введите x и y: " << endl;
                cin >> obj_x >> obj_y;
                dot1->step_on(obj_x, obj_y);
                break;
            }
            case 2:
            {
                cout << "Введите x и y: " << endl;
                cin >> obj_x >> obj_y;
                bag->step_on(obj_x, obj_y);
                break;
            }
            default:
            {
                break;
            }
            }
            break;
            
        }
        case 2:
        {
            cout << "Класс объекта?" << endl
            << "1. Object." << endl
            << "2. UserEquipment." << endl;
            cin >> menu_ch;
            switch (menu_ch) {
            case 1:
            {
                cout << "\nПозиция до перемещения";
                dot1->current_pos_check();
                dot1->random_walk();
                cout << "\nПозиция после перемещения";
                dot1->current_pos_check();
                break;
            }
            case 2:
            {
                cout << "\nПозиция до перемещения";
                bag->current_pos_check();
                bag->random_walk();
                cout << "\nПозиция после перемещения";
                bag->current_pos_check();
                break;
            }
            default:
            {    
                break;
            }
            }
            break;
        }
        case 3:
        {
            cout << "Класс объекта?" << endl
            << "1. Object." << endl
            << "2. UserEquipment." << endl;
            cin >> menu_ch;
            switch (menu_ch) {
            case 1:
            {
                cout << "Текущая позиция: " << endl;
                dot1->current_pos_check();
                break;
            }
            case 2:
            {
                cout << "Текущая позиция: " << endl;
                bag->current_pos_check();
                break;
            }
            default:
            {    
                break;
            }
            }
            break;
        }
        case 4:
        {
            cout << "Класс объекта?" << endl
            << "1. Object." << endl
            << "2. UserEquipment." << endl;
            cin >> menu_ch;
            switch (menu_ch) {
            case 1:
            {
                cout << "Весь пройденный путь: " << endl;
                dot1->path_print();
                break;
            }
            case 2:
            {
                cout << "Весь пройденный путь: " << endl;
                bag->path_print();
                break;
            }
            default:
            {    
                break;
            }
            }
            break;
        }
        case 5:
            interface();
            break;
        case 6:
            return 0;
            break;
        default:
            break;
        }
    }
}