#include <stdio.h>
#include <string.h>
#include "contact.h"


void ContactInit(struct Contact* c,
                            struct Person p, struct Phone t, struct Email e){
if(c == NULL) return;
ContactUnInit(c);
c->e = e;
c->p = p;
c->t = t;

}

void ContactPrint(struct Contact* c){
    if(c == NULL) return;
    printf("Name "); PersonPrint(&(c->p));
    printf("Phone: "); PhonePrint(&(c->t));
    printf("Email: "); EmailPrint(&(c->e));
}

void ContactUnInit(struct Contact* c){
    if(c == NULL) return;
    PersonUnInit(&(c->p));
    PhoneUnInit(&(c->t));
    EmailUnInit(&(c->e));
}