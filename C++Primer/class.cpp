#include<iostream>
#include<string>
#include<vector>

class Screen;
class Window_mgr;

extern std::ostream storeOn(std::ostream &, Screen &);
//extern BitMap& storeOn(BitMap &, Screen &); 这个BitMap类型的store则不是友元 

class Screen
{
    friend std::ostream storeOn(std::ostream &, Screen &);
    friend class Window_mgr;
public:
    using pos = std::string::size_type;
    Screen &set(char);
    Screen &set(pos, pos, char); //用于为一个Screen对象赋值
    Screen() = default;
    Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht * wd, c) { }
    char get() const //get重载，只要参数类型或数量有区别即可
        { return contents[cursor];}
    inline char get(pos ht, pos wd) const; //添加inline以显式地声明为内联函数，声明在类内即使不加inline也会隐式声明为内联函数
    Screen &move(pos r, pos c); //隐式内联
    void some_number() const;
    void setHeight(pos);

    //根据对象是否const重载display函数
    Screen &display(std::ostream &os)
        { do_display(os); return *this; }
    const Screen &display(std::ostream &os) const
        { do_display(os); return *this; }

private:
    mutable size_t access_ctr;
    pos cursor = 0;
    pos height = 0, width = 0;
    pos size() const;
    std::string contents;
    //该成员负责显示display的内容
    void do_display(std::ostream &os) const {os << contents;}
};

Screen::pos Screen::size() const
{
    return height * width;
}

inline Screen &Screen::set(char c)
{
    contents[cursor] = c;
    return *this;
}

inline Screen &Screen::set(pos r, pos col, char ch)
{
    contents[r*width + col] = ch;
    return *this;
}

inline
Screen &Screen::move(pos r, pos c)
{
    pos row = r * width;
    cursor = row + c;
    return *this;
}

char Screen::get(pos r, pos c) const
{
    pos row = r * width;
    return contents[row + c];
}

void Screen::some_number() const
{
    ++access_ctr; //计数值，用于记录成员函数的调用次数
}

Screen::pos verify(Screen::pos);
void Screen::setHeight(pos var)
{
    height = verify(var);
}

class Window_mgr {
public:
    //ScreenIndex为窗口中每个屏幕的编号
    using ScreenIndex = std::vector<Screen>::size_type;
    void clear(ScreenIndex);
    //addScreen向窗口中添加一个Screen，并返回他的编号
    ScreenIndex addScreen(const Screen &);
private:
    std::vector<Screen> screens{Screen(24, 80, ' ')};
};

void Window_mgr::clear(ScreenIndex i)
{
    Screen &s = screens[i];
    s.contents = std::string(s.height * s.width, ' ');
}

Window_mgr::ScreenIndex Window_mgr::addScreen(const Screen &s)
{
    screens.push_back(s);
    return screens.size() - 1;
}