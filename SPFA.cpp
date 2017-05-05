int spfa_bfs(int s)
{
    queue <int> q;
    memset(d,0x3f,sizeof(d));
    d[s]=0;
    memset(c,0,sizeof(c));
    memset(vis,0,sizeof(vis));
    
    q.push(s);  vis[s]=1; c[s]=1;
    //顶点入队vis要做标记，另外要统计顶点的入队次数
    int OK=1;
    while(!q.empty())
    {
        int x;
        x=q.front(); q.pop();  vis[x]=0;
        //队头元素出队，并且消除标记
        for(int k=f[x]; k!=0; k=nnext[k]) //遍历顶点x的邻接表
        {
            int y=v[k];
            if( d[x]+w[k] < d[y])
            {
                d[y]=d[x]+w[k];  //松弛
                if(!vis[y])  //顶点y不在队内
                {
                    vis[y]=1;    //标记
                    c[y]++;      //统计次数
                    q.push(y);   //入队
                    if(c[y]>NN)  //超过入队次数上限，说明有负环
                        return OK=0;
                }
            }
        }
    }
    
    return OK;
    
}


int spfa_dfs(int u)
{
    vis[u]=1;
    for(int k=f[u]; k!=0; k=e[k].next)
    {
        int v=e[k].v,w=e[k].w;
        if( d[u]+w < d[v] )
        {
            d[v]=d[u]+w;
            if(!vis[v])
            {
                if(spfa_dfs(v))
                    return 1;
            }
            else
                return 1;
        }
    }
    vis[u]=0;
    return 0;
}
