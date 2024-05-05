#include <iostream>

#include "decorator.h"

int main()
{

    auto text_a = new Paragraph(new Reversed(new Text()));
    text_a->render("Hello Mars!");

    auto link_a = new Link(new ItalicText(new Text()));
    link_a->render("netology.ru", "Happy Place");

    return 0;
}
