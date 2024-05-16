#include "editor.h"
#include <iostream>

TextEditor::TextEditor() : cursor_position(0, 0)
{
    data.push_back("");
}

void TextEditor::moveCursor(Position dest)
{
    if(s_beg != s_const && s_end != s_const)
    {
        s_beg = s_const;
        s_end = s_const;
    }
    cursor_position = dest;
}

void TextEditor::select(Position beg, Position end)
{
    s_beg = beg;
    s_end = end;
}

void TextEditor::del()
{
    if(s_beg == s_const && s_end == s_const)
    {
        int row = cursor_position.first;
        int col = cursor_position.second;
        if(col == data[row].length())
        {
            if(row == data.size() - 1)
            {
                return;
            }
            data[row] += data[static_cast<std::vector<std::string, std::allocator<std::string>>::size_type>(row) + 1];
            for (int i = row + 1; i < data.size() - 1; i++)
            {
                data[i] = data[static_cast<std::vector<std::string, std::allocator<std::string>>::size_type>(i) + 1];
            }
            data.pop_back();
        }
        else
            data[row].erase(col, 1);
    }
    else
    {
        if(s_beg.first == s_end.first)
        {
            data[s_beg.first].erase(s_beg.second, static_cast<std::basic_string<char, std::char_traits<char>, std::allocator<char>>::size_type>(s_end.second) - s_beg.second);
        }
        else
        {
            data[s_beg.first].erase(s_beg.second, data[s_beg.first].length() - s_beg.second);
            data[s_end.first].erase(0, s_end.second);
            data[s_beg.first] += data[s_end.first];
            int j = s_end.first - s_beg.first;
            for (int i = s_beg.first + 1; i <= data.size() - 1 - j; i++)
            {
                data[i] = data[static_cast<std::vector<std::string, std::allocator<std::string>>::size_type>(i) + j];
            }
            for (int k = 0; k < j; k++)
            {
                data.pop_back();
            }
        }
        Position newpo(s_beg.first, s_beg.second);
        s_beg = s_const;
        s_end = s_const;
        moveCursor(newpo);
    }
}

void TextEditor::write(const std::string& str)
{
    if(s_beg == s_const && s_end == s_const)
    {
        int row = cursor_position.first;
        int col = cursor_position.second;
        data[row].insert(col, str);
        Position newpo(row, col + str.length());
        moveCursor(newpo);
    }
    else
    {
        del();
        write(str);
    }
}

void TextEditor::newline()
{
    if(s_beg == s_const && s_end == s_const)
    {
        int row = cursor_position.first;
        int col = cursor_position.second;
        data.push_back("");
        for (int i = data.size() - 1; i >= row + 1; i--)
        {
            data[i] = data[static_cast<std::vector<std::string, std::allocator<std::string>>::size_type>(i) - 1];
        }
        data[row].erase(col, data[row].size() - col);
        data[static_cast<std::vector<std::string, std::allocator<std::string>>::size_type>(row) + 1].erase(0, col);
        Position newpo(row + 1, 0);
        moveCursor(newpo);
    }
    else
    {
        del();
        newline();
    }
}

void TextEditor::copy()
{
    if(s_beg == s_const && s_end == s_const)
        return;
    int cur_size = clipboard.size();
    for (int i = 0; i < cur_size; i++)
    {
        clipboard.pop_back();
    }
    int j = s_end.first - s_beg.first;
    for (int i = 0; i <= j; i++)
    {
        clipboard.push_back(data[static_cast<std::vector<std::string, std::allocator<std::string>>::size_type>(i) + s_beg.first]);
    }
    if(j == 0)
        clipboard[0] = clipboard[0].substr(s_beg.second, static_cast<std::basic_string<char, std::char_traits<char>, std::allocator<char>>::size_type>(s_end.second) - s_beg.second);
    else
    {
        int k = clipboard.size() - 1;
        clipboard[0].erase(0, s_beg.second);
        clipboard[k].erase(s_end.second, clipboard[k].length() - s_end.second);
    }
}

void TextEditor::paste()
{
    
    if(s_beg == s_const && s_end == s_const)
    {
        if (clipboard.size() == 0)
            return;
        int row = cursor_position.first;
        int col = cursor_position.second;
        int j = clipboard.size() - 1;
        for (int i = 0; i < j; i++)
        {
            data.push_back("");
        }
        for (int i = data.size() - 1; i >= row + j; i--)
        {
            data[i] = data[static_cast<std::vector<std::string, std::allocator<std::string>>::size_type>(i) - j];
        }
        for (int i = row + 1; i <= row + j; i++)
        {
            data[i] = clipboard[static_cast<std::vector<std::string, std::allocator<std::string>>::size_type>(i) - row];
        }
        std::string temp = data[row].substr(col, data[row].size() - col);
        data[row].erase(col, data[row].size() - col);
        data[row] += clipboard[0];
        int l = data[static_cast<std::vector<std::string, std::allocator<std::string>>::size_type>(row) + j].length();
        data[static_cast<std::vector<std::string, std::allocator<std::string>>::size_type>(row) + j] += temp;
        Position newpo(row + j, l);
        moveCursor(newpo);
    }
    else
    {
        del();
        paste();
    }
}

void TextEditor::screenShot()
{
    if(s_beg == s_const && s_end == s_const)
    {
        int row = cursor_position.first;
        int col = cursor_position.second;
        for (int i = 0; i < data.size(); i++)
        {
            if(i != row)
            {
                std::cout << data[i];
                if(i != data.size() - 1) 
                    std::cout << std::endl;
            }
            else
            {
                for (int j = 0; j < col; j++)
                {
                    std::cout << data[i][j];
                }
                std::cout << '*';
                int k = data[i].length() - 1;
                for (int j = col; j <= k; j++)
                {
                    std::cout << data[i][j];
                }
                if (i != data.size() - 1)
                    std::cout << std::endl;
            }
        }
    }
    else
    {
        int row1 = s_beg.first;
        int col1 = s_beg.second;
        int row2 = s_end.first;
        int col2 = s_end.second;
        for (int i = 0; i < data.size(); i++)
        {
            if(i != row1 && i != row2)
            {
                std::cout << data[i];
                if (i != data.size() - 1)
                    std::cout << std::endl;
            }
            else if(i == row1 && i != row2)
            {
                for (int j = 0; j < col1; j++)
                {
                    std::cout << data[i][j];
                }
                std::cout << '*';
                int k = data[i].length() - 1;
                for (int j = col1; j <= k; j++)
                {
                    std::cout << data[i][j];
                }
                if (i != data.size() - 1)
                    std::cout << std::endl;
            }
            else if(i == row2 && i != row1)
            {
                for (int j = 0; j < col2; j++)
                {
                    std::cout << data[i][j];
                }
                std::cout << '*';
                int k = data[i].length() - 1;
                for (int j = col2; j <= k; j++)
                {
                    std::cout << data[i][j];
                }
                if (i != data.size() - 1)
                    std::cout << std::endl;
            }
            else
            {
                if (col2 == col1)
                {
                    for (int j = 0; j < col2; j++)
                    {
                        std::cout << data[i][j];
                    }
                    std::cout << "**";
                    int k = data[i].length() - 1;
                    for (int j = col2; j <= k; j++)
                    {
                        std::cout << data[i][j];
                    }
                    if (i != data.size() - 1)
                        std::cout << std::endl;
                }
                else
                {
                    for (int j = 0; j < col1; j++)
                    {
                        std::cout << data[i][j];
                    }
                    std::cout << '*';
                    for (int j = col1; j < col2; j++)
                    {
                        std::cout << data[i][j];
                    }
                    std::cout << '*';
                    int k = data[i].length() - 1;
                    for (int j = col2; j <= k; j++)
                    {
                        std::cout << data[i][j];
                    }
                    if (i != data.size() - 1)
                        std::cout << std::endl;
                }
            }
        }
    }
}