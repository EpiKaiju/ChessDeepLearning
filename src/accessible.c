//team 0 = en haut
//team 1 = en bas


//return 1 = success
//return 0 = fail

void makeAccessible(int ** board, int x, int y)
{
		board[x][y] *= -1;
		if(board[x][y] == 0)
			board[x][y] = -20;
}


int pawnAcc(int ** board, int x, int y, int team)
{
	if(team == 0 && (board[x+1][y] <= 0 || board[x+1][y] >= 10))
	{
			board[x+1][y] *= -1;
			if(board[x+1][y] == 0)
				board[x+1][y] = -20;
			return 1;
	}			board[x+1][y] = -1;

	if(team == 1 && board[x-1][y] < 10)
	{
			board[x+1][y] *= -1;
			if(board[x+1][y] == 0)
				board[x+1][y] = -20;
			return 1;
	}
	
	return 0;
}

int rookAcc(int ** board, int x, int y, int team)
{
	int enemy = 0;
	int ret = 0;
	int i = x+1;
	int j = y;
	while((i >= 0 && i < 8) && (board[i][j] == 0 || board[i][j]/10 != team) &&
			enemy ==0)
	{
		board[i][j] *= -1;
		if(board[i][j] == 0)
			board[i][j] = -20;
		else
			enemy = 1;
		i++;
		ret++;
	}
	i = x-1;
	j = y;
	enemy = 0;
	while((i >= 0 && i < 8) && (board[i][j] == 0 || board[i][j]/10 != team))
	{
		board[i][j] *= -1;
		if(board[i][j] == 0)
			board[i][j] = -20;
		else
			enemy = 1;
		i--;
		ret++;
	}
	i = x;
	j = y+1;
	enemy = 0;
	while((j >= 1 && j < 9) && (board[i][j] == 0 || board[i][j]/10 != team))
	{
		board[i][j] *= -1;
		if(board[i][j] == 0)
			board[i][j] = -20;
		else
			enemy = 1;
		j++;
		ret++;
	}
	i = x;
	j = y-1;
	enemy = 0;
	while((j >= 1 && j < 9) && (board[i][j] == 0 || board[i][j]/10 != team))
	{
		board[i][j] *= -1;
		if(board[i][j] == 0)
			board[i][j] = -20;
		else
			enemy = 1;
		j--;
		ret++;
	}

	return ret == 0 ? 0 : 1;
}

int bishopAcc(int ** board, int x, int y, int team)
{
	int enemy = 0;
	int ret = 0;
	int i = x+1;
	int j = y+1;
	while(i >= 0 && i < 8 && j >= 1 && j < 9
			&& (board[i][j] == 0 || board[i][j]/10 != team) && enemy ==0)
	{
		board[i][j] *= -1;
		if(board[i][j] == 0)
			board[i][j] = -20;
		else
			enemy = 1;
		i++;
		j++;
		ret++;
	}

	enemy = 0;
	i = x-1;
	j = y-1;
	while(i >= 0 && i < 8 && j >= 1 && j < 9
			&& (board[i][j] == 0 || board[i][j]/10 != team) && enemy ==0)
	{
		board[i][j] *= -1;
		if(board[i][j] == 0)
			board[i][j] = -20;
		else
			enemy = 1;
		i--;
		j--;
		ret++;
	}

	enemy = 0;
	i = x+1;
	j = y-1;
	while(i >= 0 && i < 8 && j >= 1 && j < 9
			&& (board[i][j] == 0 || board[i][j]/10 != team) && enemy ==0)
	{
		board[i][j] *= -1;
		if(board[i][j] == 0)
			board[i][j] = -20;
		else
			enemy = 1;
		i++;
		j--;
		ret++;
	}

	enemy = 0;
	i = x-1;
	j = y+1;
	while(i >= 0 && i < 8 && j >= 1 && j < 9
			&& (board[i][j] == 0 || board[i][j]/10 != team) && enemy ==0)
	{
		board[i][j] *= -1;
		if(board[i][j] == 0)
			board[i][j] = -20;
		else
			enemy = 1;
		i--;
		j++;
		ret++;
	}


	return ret == 0 ? 0 : 1;

}

int horseAcc(int ** board, int x, int y, int team)
{
	if(x+2 < 8 && y+1 < 9 && (board[x+2][y+1]/10 != team || 
				board[x+2][y+1]==0))
		makeAccessible(board, x+2, y+1);
	
	if(x+2 < 8 && y-1 < 9 && (board[x+2][y-1]/10 != team || 
			board[x+2][y-1]==0))
		makeAccessible(board, x+2, y-1);
	
	if(x-2 < 8 && y+1 < 9 && (board[x-2][y+1]/10 != team || 
				board[x-2][y+1]==0))
			makeAccessible(board, x-2, y+1);
	
	if(x-2 < 8 && y-1 < 9 && (board[x-2][y-1]/10 != team || 
				board[x-2][y-1]==0))
		makeAccessible(board, x-2, y-1);
	
	if(x+1 < 8 && y+2 < 9 && (board[x+1][y+2]/10 != team || 
				board[x+1][y+2]==0))
		makeAccessible(board, x+1, y+2);
	
	if(x+1 < 8 && y-2 < 9 && (board[x+1][y-2]/10 != team || 
				board[x+1][y-2]==0))
		makeAccessible(board, x+1, y-2);
	
	if(x-1 < 8 && y+2 < 9 && (board[x-1][y+2]/10 != team || 
				board[x-1][y+2]==0))
		makeAccessible(board, x-1, y+2);

	if(x-1 < 8 && y-2 < 9 && (board[x-1][y-2]/10 != team || 
				board[x-1][y-2]==0))
		makeAccessible(board, x-1, y-2);

	return 1;
}

int queenAcc(int ** board, int x, int y, int team)
{
	int ret = bishopAcc(board, x, y, team) && rookAcc(board, x ,y, team);
	return ret;
}

int kingAcc(int ** board, int x, int y, int team)
{
	if(x+1 < 8 && y+1 < 9 && (board[x+1][y+1]/10 != team || 
				board[x+1][y+1]==0))
		makeAccessible(board, x+1, y+1);
	
	if(x+1 < 8 && y-1 < 9 && (board[x+1][y-1]/10 != team || 
			board[x+1][y-1]==0))
		makeAccessible(board, x+1, y-1);
	
	if(x+1 < 8 && y < 9 && (board[x+1][y]/10 != team || 
				board[x+1][y]==0))
			makeAccessible(board, x+1, y);
	
	if(x < 8 && y-1 < 9 && (board[x][y-1]/10 != team || 
				board[x][y-1]==0))
		makeAccessible(board, x, y-1);
	
	if(x < 8 && y+1 < 9 && (board[x][y+1]/10 != team || 
				board[x][y+1]==0))
		makeAccessible(board, x, y+1);
	
	if(x-1 < 8 && y < 9 && (board[x-1][y]/10 != team || 
				board[x-1][y]==0))
		makeAccessible(board, x-1, y);
	
	if(x-1 < 8 && y-1 < 9 && (board[x-1][y-1]/10 != team || 
				board[x-1][y-1]==0))
		makeAccessible(board, x-1, y-1);

	if(x-1 < 8 && y+1 < 9 && (board[x-1][y+1]/10 != team || 
				board[x-1][y+1]==0))
		makeAccessible(board, x-1, y+1);

	return 1;

}

