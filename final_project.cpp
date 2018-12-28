class Student{
public:
    void makeMove(int Record[5][6], int Max[5][6], Color color[5][6], Color inputColor)
    {
        x = 0; y = 0; myCM_x = 0; myCM_y = 0; enemyCM_x = 0; enemyCM_y = 0; corner_x = 0; corner_y = 0; near_x = 0; near_y = 0; empty_x = 0;
        empty_y = 0; myCell_x = 0; myCell_y = 0; kill_x = 0; kill_y = 0;

        if(inputColor == Red) enemyColor = Blue;
        else enemyColor = Red;
        if(enemyCM(Record, Max, color, inputColor))
        {
            if(myCM_near_enemyCM(Record, Max, color, inputColor))
            {
                x = kill_x;
                y = kill_y;
            }
            else if(myCM(Record, Max, color, inputColor))
            {
                if(enemy_near_myCM(Record, Max, color, inputColor))
                {
                    x = kill_x;
                    y = kill_y;
                }
                else if(enemy_near_myCell(Record, Max, color, inputColor))
                {
                    x = myCell_x;
                    y = myCell_y;
                }
                /*else if(myCM_near(Record, Max, color, inputColor))
                {
                    x = near_x;
                    y = near_y;
                }*/
                else
                {
                    x = myCM_x;
                    y = myCM_y;
                }
            }
            else
            {
                if(first_time(Record, Max, color, inputColor))
                {
                    cornerEmpty(Record, Max, color, inputColor);
                    x = corner_x;
                    y = corner_y;
                }
                else
                {
                    if(myCell(Record, Max, color, inputColor))
                    {
                        x = myCell_x;
                        y = myCell_y;
                    }
                    else
                    {
                        emptyCell(Record, Max, color, inputColor);
                        x = empty_x;
                        y = empty_y;
                    }
                }
            }
        }
        else if(myCM(Record, Max, color, inputColor))
        {
            if(enemy_near_myCM(Record, Max, color, inputColor))
            {
                x = kill_x;
                y = kill_y;
            }
            else if(enemy_near_myCell(Record, Max, color, inputColor))
            {
                x = myCell_x;
                y = myCell_y;
            }
            /*else if(myCM_near(Record, Max, color, inputColor))
            {
                x = near_x;
                y = near_y;
            }*/
            else
            {
                x = myCM_x;
                y = myCM_y;
            }
        }
        else
        {
            if(myCell(Record, Max, color, inputColor))
            {
                x = myCell_x;
                y = myCell_y;
            }
            else
            {
                emptyCell(Record, Max, color, inputColor);
                x = empty_x;
                y = empty_y;
            }
        }
    }
    bool first_time(int Record[5][6], int Max[5][6], Color color[5][6], Color inputColor)
    {
        for(int i = 0; i < 5; ++i)
        {
            for(int j = 0; j < 6; ++j)
            {
                if(color[i][j] == inputColor || color[i][j] == Black)
                {
                    return false;
                }
            }
        }
        return true;
    }
    bool enemyCM(int Record[5][6], int Max[5][6], Color color[5][6], Color inputColor)
    {
        for(int i = 0; i < 5; ++i)
        {
            for(int j = 0; j < 6; ++j)
            {
                if(Record[i][j] == Max[i][j] - 1 && color[i][j] == enemyColor)
                {
                    enemyCM_x = i;
                    enemyCM_y = j;
                    return true;
                }
            }
        }
        return false;
    }
    bool enemy_near_myCM(int Record[5][6], int Max[5][6], Color color[5][6], Color inputColor)
    {
        for(int i = 0; i < 5; ++i)
        {
            for(int j = 0; j < 6; ++j)
            {
                if(Record[i][j] == Max[i][j] - 1 && color[i][j] == inputColor)
                {
                    myCM_x = i;
                    myCM_y = j;
                    for(int k = 0; k < 4; ++k)
                    {
                        if(color[myCM_x + dir_r_[k]][myCM_y + dir_c_[k]] == enemyColor &&
                           myCM_x + dir_r_[k] >= 0 && myCM_y + dir_c_[k] >= 0 &&
                           myCM_x + dir_r_[k] < 5 && myCM_y + dir_c_[k] < 6)
                        {
                            kill_x = myCM_x;
                            kill_y = myCM_y;
                            return true;
                        }
                    }
                }
            }
        }
        return false;
    }
    bool myCM_near_enemyCM(int Record[5][6], int Max[5][6], Color color[5][6], Color inputColor)
    {
        for(int i = 0; i < 5; ++i)
        {
            for(int j = 0; j < 6; ++j)
            {
                if(Record[i][j] == Max[i][j] - 1 && color[i][j] == enemyColor)
                {
                    enemyCM_x = i;
                    enemyCM_y = j;
                    for(int k = 0; k < 4; ++k)
                    {
                        if(color[enemyCM_x + dir_r_[k]][enemyCM_y + dir_c_[k]] == inputColor &&
                           Record[enemyCM_x + dir_r_[k]][enemyCM_y + dir_c_[k]] == Max[enemyCM_x + dir_r_[k]][enemyCM_y + dir_c_[k]] - 1 &&
                           enemyCM_x + dir_r_[k] >= 0 && enemyCM_y + dir_c_[k] >= 0 &&
                           enemyCM_x + dir_r_[k] < 5 && enemyCM_y + dir_c_[k] < 6)
                        {
                            kill_x = enemyCM_x + dir_r_[k];
                            kill_y = enemyCM_y + dir_c_[k];
                            return true;
                        }
                    }
                }
            }
        }
        return false;
    }
    bool enemy_near_myCell(int Record[5][6], int Max[5][6], Color color[5][6], Color inputColor)
    {
        for(int i = 0; i < 5; ++i)
        {
            for(int j = 0; j < 6; ++j)
            {
                if(color[i][j] == inputColor)
                {
                    for(int k = 0; k < 4; ++k)
                    {
                        if(color[i + dir_r_[k]][j + dir_c_[k]] == enemyColor &&
                           0 <= i + dir_r_[k] && i + dir_r_[k] < 5 &&
                           0 <= j + dir_c_[k] && j + dir_c_[k] < 6 &&
                           Max[i][j] - Record[i][j] <= Max[i + dir_r_[k]][j + dir_c_[k]] - Record[i + dir_r_[k]][j + dir_c_[k]])
                        {
                            myCell_x = i;
                            myCell_y = j;
                            return true;
                        }
                    }
                }
            }
        }
        return false;
    }
    bool myCM(int Record[5][6], int Max[5][6], Color color[5][6], Color inputColor)
    {
        for(int i = 0; i < 5; ++i)
        {
            for(int j = 0; j < 6; ++j)
            {
                if(Record[i][j] == Max[i][j] - 1 && color[i][j] == inputColor)
                {
                    myCM_x = i;
                    myCM_y = j;
                    return true;
                }
            }
        }
        return false;
    }
    bool myCM_near(int Record[5][6], int Max[5][6], Color color[5][6], Color inputColor)
    {
        for(int i = 0; i < 4; ++i)
        {
            if(color[myCM_x + dir_r_[i]][myCM_y + dir_c_[i]] == White &&
                myCM_x + dir_r_[i] >= 0 && myCM_y + dir_c_[i] >= 0 &&
                myCM_x + dir_r_[i] < 5 && myCM_y + dir_c_[i] < 6)
            {
                near_x = myCM_x + dir_r_[i];
                near_y = myCM_y + dir_c_[i];
                return true;
            }
        }
        return false;
    }
    bool cornerEmpty(int Record[5][6], int Max[5][6], Color color[5][6], Color inputColor)
    {
        for(int i = 0; i < 5; ++i)
        {
            for(int j = 0; j < 6; ++j)
            {
                if(Max[i][j] == 2 && color[i][j] == White)
                {
                    corner_x = i;
                    corner_y = j;
                    return true;
                }
            }
        }
        return false;
    }
    bool emptyCell(int Record[5][6], int Max[5][6], Color color[5][6], Color inputColor)
    {
        for(int i = 0; i < 5; ++i)
        {
            for(int j = 0; j < 6; ++j)
            {
                if(color[i][j] == White)
                {
                    empty_x = i;
                    empty_y = j;
                    return true;
                }
            }
        }
        return false;
    }
    bool myCell(int Record[5][6], int Max[5][6], Color color[5][6], Color inputColor)
    {
        for(int i = 0; i < 5; ++i)
        {
            for(int j = 0; j < 6; ++j)
            {
                if(color[i][j] == inputColor)
                {
                    myCell_x = i;
                    myCell_y = j;
                    return true;
                }
            }
        }
        return false;
    }
    int getX()
    {
        return x;
    }
    int getY()
    {
        return y;
    }
private:
    int x;
    int y;
    int myCM_x, myCM_y;
    int enemyCM_x, enemyCM_y;
    int corner_x;
    int corner_y;
    int near_x;
    int near_y;
    int empty_x;
    int empty_y;
    int myCell_x;
    int myCell_y;
    int kill_x;
    int kill_y;
    Color enemyColor;
    //bool last;
    //int last_x;
    //int last_y;
    const int dir_r_[4] = {1, -1, 0, 0};
    const int dir_c_[4] = {0, 0, 1, -1};
};
