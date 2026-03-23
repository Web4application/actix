NAME
Srv, dirread9p, emalloc9p, erealloc9p, estrdup9p, listensrv, postfd, postmountsrv, readbuf, readstr, respond, responderror, threadlistensrv, threadpostmountsrv, srv – 9P file service

SYNOPSIS
#include <u.h>
#include <libc.h>
#include <fcall.h>
#include <thread.h>
#include <9p.h>
typedef struct Srv {
Tree* tree;
void    (*attach)(Req *r);
void    (*auth)(Req *r);
void    (*open)(Req *r);
void    (*create)(Req *r);
void    (*read)(Req *r);
void    (*write)(Req *r);
void    (*remove)(Req *r);
void    (*flush)(Req *r);
void    (*stat)(Req *r);
void    (*wstat)(Req *r);
void    (*walk)(Req *r);
char* (*walk1)(Fid *fid, char *name, Qid *qid);
char* (*clone)(Fid *oldfid, Fid *newfid);
void    (*destroyfid)(Fid *fid);
void    (*destroyreq)(Req *r);
void    (*end)(Srv *s);
void* aux;
int     infd;
int     outfd;
int     srvfd;
int     nopipe;
} Srv;

int     srv(Srv *s)
void    postmountsrv(Srv *s, char *name, char *mtpt, int flag)
void    threadpostmountsrv(Srv *s, char *name, char *mtpt, int flag)
void    listensrv(Srv *s, char *addr)
void    threadlistensrv(Srv *s, char *addr)
int     postfd(char *srvname, int fd)
void    respond(Req *r, char *error)
void    responderror(Req*)
void    readstr(Re
