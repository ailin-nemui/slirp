void so_init _P((void));
struct socket * solookup _P((struct socket *, struct in_addr, u_int, struct in_addr, u_int));
struct socket * socreate _P((void));
void sofree _P((struct socket *));
int soread _P((struct socket *));
void sorecvoob _P((struct socket *));
int sosendoob _P((struct socket *));
int sowrite _P((struct socket *));
void sorecvfrom _P((struct socket *));
int sosendto _P((struct socket *, struct mbuf *));
struct socket * solisten _P((u_int, u_int32_t, u_int, int));
void sorwakeup _P((struct socket *));
void sowwakeup _P((struct socket *));
void soisfconnecting _P((register struct socket *));
void soisfconnected _P((register struct socket *));
void sofcantrcvmore _P((struct socket *));
void sofcantsendmore _P((struct socket *));
void soisfdisconnected _P((struct socket *));
void sofwdrain _P((struct socket *));
