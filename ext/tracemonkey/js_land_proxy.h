#ifndef JOHNSON_TRACEMONKEY_JS_LAND_PROXY_H
#define JOHNSON_TRACEMONKEY_JS_LAND_PROXY_H

#include "tracemonkey.h"
#include "runtime.h"

bool js_value_is_proxy(JohnsonRuntime* runtime, jsval maybe_proxy);
VALUE unwrap_js_land_proxy(JohnsonRuntime* runtime, jsval proxy);
JSBool make_js_land_proxy(JohnsonRuntime* runtime, VALUE value, jsval* retval);

#if false
#include "node.h"
#else

typedef struct RNode {
    unsigned long flags;
    char *nd_file;
    union {
	struct RNode *node;
	ID id;
	VALUE value;
	VALUE (*cfunc)(ANYARGS);
	ID *tbl;
    } u1;
    union {
	struct RNode *node;
	ID id;
	long argc;
	VALUE value;
    } u2;
    union {
	struct RNode *node;
	ID id;
	long state;
	struct global_entry *entry;
	long cnt;
	VALUE value;
    } u3;
} NODE;

#define NODE_IVAR 51
#define NODE_TYPESHIFT 8
#define NODE_TYPEMASK  (((VALUE)0x7f)<<NODE_TYPESHIFT)
#define RNODE(obj)  (R_CAST(RNode)(obj))
#define nd_type(n) ((int) (((RNODE(n))->flags & NODE_TYPEMASK)>>NODE_TYPESHIFT))

#endif

// typedef enum {
//     NOEX_PUBLIC    = 0x00,
//     NOEX_NOSUPER   = 0x01,
//     NOEX_PRIVATE   = 0x02,
//     NOEX_PROTECTED = 0x04,
//     NOEX_MASK      = 0x06,
//     NOEX_BASIC     = 0x08,
//     NOEX_UNDEF     = NOEX_NOSUPER,
//     NOEX_MODFUNC   = 0x12,
//     NOEX_SUPER     = 0x20,
//     NOEX_VCALL     = 0x40,
//     NOEX_RESPONDS  = 0x80
// } rb_method_flag_t;
// 
// typedef enum {
//     VM_METHOD_TYPE_ISEQ,
//     VM_METHOD_TYPE_CFUNC,
//     VM_METHOD_TYPE_ATTRSET,
//     VM_METHOD_TYPE_IVAR,
//     VM_METHOD_TYPE_BMETHOD,
//     VM_METHOD_TYPE_ZSUPER,
//     VM_METHOD_TYPE_UNDEF,
//     VM_METHOD_TYPE_NOTIMPLEMENTED,
//     VM_METHOD_TYPE_OPTIMIZED, /* Kernel#send, Proc#call, etc */
//     VM_METHOD_TYPE_MISSING   /* wrapper for method_missing(id) */
// } rb_method_type_t;
// 
// typedef struct rb_method_cfunc_struct {
//     VALUE (*func)(ANYARGS);
//     int argc;
// } rb_method_cfunc_t;
// 
// typedef struct rb_method_attr_struct {
//     ID id;
//     VALUE location;
// } rb_method_attr_t;
// 
// typedef struct rb_iseq_struct rb_iseq_t;
// 
// typedef struct rb_method_definition_struct {
//     rb_method_type_t type; /* method type */
//     ID original_id;
//     union {
//      rb_iseq_t *iseq;            /* should be mark */
//      rb_method_cfunc_t cfunc;
//      rb_method_attr_t attr;
//      VALUE proc;                 /* should be mark */
//      enum method_optimized_type {
//          OPTIMIZED_METHOD_TYPE_SEND,
//          OPTIMIZED_METHOD_TYPE_CALL
//      } optimize_type;
//     } body;
//     int alias_count;
// } rb_method_definition_t;
// 
// typedef struct rb_method_entry_struct {
//     rb_method_flag_t flag;
//     char mark;
//     rb_method_definition_t *def;
//     ID called_id;
//     VALUE klass;                    /* should be mark */
// } rb_method_entry_t;
// 
// struct unlinked_method_entry_list_entry {
//     struct unlinked_method_entry_list_entry *next;
//     rb_method_entry_t *me;
// };
// 
// 
// struct METHOD {
//     VALUE recv;
//     VALUE rclass;
//     ID id;
//     rb_method_entry_t *me;
//     struct unlinked_method_entry_list_entry *ume;
// };


#endif
