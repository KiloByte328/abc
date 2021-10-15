#ifndef MRK
#define MRK
enum keys
{

};

int rk_readKey (enum keys *k);
int rk_saveterm ();
int rk_loadterm();
int termregim (int regime, int vtime, int vmin, int echo, int sigint);

#endif // !MyReadkey