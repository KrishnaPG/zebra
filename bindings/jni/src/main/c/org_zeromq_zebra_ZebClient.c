/*
################################################################################
#  THIS FILE IS 100% GENERATED BY ZPROJECT; DO NOT EDIT EXCEPT EXPERIMENTALLY  #
#  Please refer to the README for information about making permanent changes.  #
################################################################################
*/
#include <stdio.h>
#include <stdlib.h>
#include <jni.h>
#include "zebra.h"
#include "org_zeromq_zebra_ZebClient.h"

JNIEXPORT jlong JNICALL
Java_org_zeromq_zebra_ZebClient__1_1new (JNIEnv *env, jclass c)
{
    //  Disable CZMQ signal handling; allow Java to deal with it
    zsys_handler_set (NULL);
    jlong new_ = (jlong) (intptr_t) zeb_client_new ();
    return new_;
}

JNIEXPORT void JNICALL
Java_org_zeromq_zebra_ZebClient__1_1destroy (JNIEnv *env, jclass c, jlong self)
{
    zeb_client_destroy ((zeb_client_t **) &self);
}

JNIEXPORT jlong JNICALL
Java_org_zeromq_zebra_ZebClient__1_1actor (JNIEnv *env, jclass c, jlong self)
{
    jlong actor_ = (jlong) (intptr_t) zeb_client_actor ((zeb_client_t *) (intptr_t) self);
    return actor_;
}

JNIEXPORT jlong JNICALL
Java_org_zeromq_zebra_ZebClient__1_1msgpipe (JNIEnv *env, jclass c, jlong self)
{
    jlong msgpipe_ = (jlong) (intptr_t) zeb_client_msgpipe ((zeb_client_t *) (intptr_t) self);
    return msgpipe_;
}

JNIEXPORT jboolean JNICALL
Java_org_zeromq_zebra_ZebClient__1_1connected (JNIEnv *env, jclass c, jlong self)
{
    jboolean connected_ = (jboolean) zeb_client_connected ((zeb_client_t *) (intptr_t) self);
    return connected_;
}

JNIEXPORT jint JNICALL
Java_org_zeromq_zebra_ZebClient__1_1connect (JNIEnv *env, jclass c, jlong self, jstring endpoint, jint timeout, jstring address)
{
    char *endpoint_ = (char *) (*env)->GetStringUTFChars (env, endpoint, NULL);
    char *address_ = (char *) (*env)->GetStringUTFChars (env, address, NULL);
    jint connect_ = (jint) zeb_client_connect ((zeb_client_t *) (intptr_t) self, endpoint_, (uint32_t) timeout, address_);
    (*env)->ReleaseStringUTFChars (env, endpoint, endpoint_);
    (*env)->ReleaseStringUTFChars (env, address, address_);
    return connect_;
}

JNIEXPORT jint JNICALL
Java_org_zeromq_zebra_ZebClient__1_1setHandler (JNIEnv *env, jclass c, jlong self, jstring method, jstring route)
{
    char *method_ = (char *) (*env)->GetStringUTFChars (env, method, NULL);
    char *route_ = (char *) (*env)->GetStringUTFChars (env, route, NULL);
    jint set_handler_ = (jint) zeb_client_set_handler ((zeb_client_t *) (intptr_t) self, method_, route_);
    (*env)->ReleaseStringUTFChars (env, method, method_);
    (*env)->ReleaseStringUTFChars (env, route, route_);
    return set_handler_;
}

JNIEXPORT jint JNICALL
Java_org_zeromq_zebra_ZebClient__1_1request (JNIEnv *env, jclass c, jlong self, jint timeout, jlong content)
{
    jint request_ = (jint) zeb_client_request ((zeb_client_t *) (intptr_t) self, (uint32_t) timeout, (zmsg_t **) (intptr_t) &content);
    return request_;
}

JNIEXPORT jint JNICALL
Java_org_zeromq_zebra_ZebClient__1_1deliver (JNIEnv *env, jclass c, jlong self, jlong sender, jlong content)
{
    jint deliver_ = (jint) zeb_client_deliver ((zeb_client_t *) (intptr_t) self, (zuuid_t *) (intptr_t) sender, (zmsg_t **) (intptr_t) &content);
    return deliver_;
}

JNIEXPORT jlong JNICALL
Java_org_zeromq_zebra_ZebClient__1_1recv (JNIEnv *env, jclass c, jlong self)
{
    jlong recv_ = (jlong) (intptr_t) zeb_client_recv ((zeb_client_t *) (intptr_t) self);
    return recv_;
}

JNIEXPORT jstring JNICALL
Java_org_zeromq_zebra_ZebClient__1_1command (JNIEnv *env, jclass c, jlong self)
{
    char *command_ = (char *) zeb_client_command ((zeb_client_t *) (intptr_t) self);
    jstring return_string_ = (*env)->NewStringUTF (env, command_);
    return return_string_;
}

JNIEXPORT jint JNICALL
Java_org_zeromq_zebra_ZebClient__1_1status (JNIEnv *env, jclass c, jlong self)
{
    jint status_ = (jint) zeb_client_status ((zeb_client_t *) (intptr_t) self);
    return status_;
}

JNIEXPORT jstring JNICALL
Java_org_zeromq_zebra_ZebClient__1_1reason (JNIEnv *env, jclass c, jlong self)
{
    char *reason_ = (char *) zeb_client_reason ((zeb_client_t *) (intptr_t) self);
    jstring return_string_ = (*env)->NewStringUTF (env, reason_);
    return return_string_;
}

JNIEXPORT jlong JNICALL
Java_org_zeromq_zebra_ZebClient__1_1sender (JNIEnv *env, jclass c, jlong self)
{
    jlong sender_ = (jlong) (intptr_t) zeb_client_sender ((zeb_client_t *) (intptr_t) self);
    return sender_;
}

JNIEXPORT jlong JNICALL
Java_org_zeromq_zebra_ZebClient__1_1content (JNIEnv *env, jclass c, jlong self)
{
    jlong content_ = (jlong) (intptr_t) zeb_client_content ((zeb_client_t *) (intptr_t) self);
    return content_;
}

JNIEXPORT void JNICALL
Java_org_zeromq_zebra_ZebClient__1_1setVerbose (JNIEnv *env, jclass c, jlong self, jboolean verbose)
{
    zeb_client_set_verbose ((zeb_client_t *) (intptr_t) self, (bool) verbose);
}

JNIEXPORT void JNICALL
Java_org_zeromq_zebra_ZebClient__1_1test (JNIEnv *env, jclass c, jboolean verbose)
{
    zeb_client_test ((bool) verbose);
}

