/*
################################################################################
#  THIS FILE IS 100% GENERATED BY ZPROJECT; DO NOT EDIT EXCEPT EXPERIMENTALLY  #
#  Please refer to the README for information about making permanent changes.  #
################################################################################
*/

#include "qzwebrap.h"

///
//  Private copy-construct to return the proper wrapped c types
QZactor::QZactor (zactor_t *self, QObject *qObjParent) : QObject (qObjParent)
{
    this->self = self;
}


///
//  Create a new actor passing arbitrary arguments reference.
QZactor::QZactor (zactor_fn task, void *args, QObject *qObjParent) : QObject (qObjParent)
{
    this->self = zactor_new (task, args);
}

///
//  Destroy an actor.
QZactor::~QZactor ()
{
    zactor_destroy (&self);
}

///
//  Send a zmsg message to the actor, take ownership of the message
//  and destroy when it has been sent.                             
int QZactor::send (QZmsg *msgP)
{
    int rv = zactor_send (self, &msgP->self);
    return rv;
}

///
//  Receive a zmsg message from the actor. Returns NULL if the actor 
//  was interrupted before the message could be received, or if there
//  was a timeout on the actor.                                      
QZmsg * QZactor::recv ()
{
    QZmsg *rv = new QZmsg (zactor_recv (self));
    return rv;
}

///
//  Probe the supplied object, and report if it looks like a zactor_t.
bool QZactor::is (void *self)
{
    bool rv = zactor_is (self);
    return rv;
}

///
//  Probe the supplied reference. If it looks like a zactor_t instance,
//  return the underlying libzmq actor handle; else if it looks like   
//  a libzmq actor handle, return the supplied value.                  
void * QZactor::resolve (void *self)
{
    void * rv = zactor_resolve (self);
    return rv;
}

///
//  Return the actor's zsock handle. Use this when you absolutely need
//  to work with the zsock instance rather than the actor.            
QZsock * QZactor::sock ()
{
    QZsock *rv = new QZsock (zactor_sock (self));
    return rv;
}

///
//  Self test of this class.
void QZactor::test (bool verbose)
{
    zactor_test (verbose);
    
}
/*
################################################################################
#  THIS FILE IS 100% GENERATED BY ZPROJECT; DO NOT EDIT EXCEPT EXPERIMENTALLY  #
#  Please refer to the README for information about making permanent changes.  #
################################################################################
*/
