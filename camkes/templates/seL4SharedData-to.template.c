/*#
 *# Copyright 2015, NICTA
 *#
 *# This software may be distributed and modified according to the terms of
 *# the BSD 2-Clause license. Note that NO WARRANTY is provided.
 *# See "LICENSE_BSD2.txt" for details.
 *#
 *# @TAG(NICTA_BSD)
 #*/

#include <camkes/dataport.h>
#include <stdint.h>
#include <stdlib.h>
#include <utils/util.h>

/*? macros.show_includes(me.instance.type.includes) ?*/

/*- set index = me.parent.to_ends.index(me) -*/

struct {
    char content[ROUND_UP_UNSAFE(/*? macros.dataport_size(me.interface.type) ?*/,
        PAGE_SIZE_4K)];
} to_/*? index ?*/_/*? me.interface.name ?*/_data
        __attribute__((section("shared_to_/*? index ?*/_/*? me.interface.name ?*/")));
/*- set perm = configuration[me.instance.name].get('%s_access' % me.interface.name) -*/
/*- if perm is not none and not re.match('^R?W?X?$', perm) -*/
  /*? raise(TemplateError('invalid permissions attribute %s.%s_access' % (me.instance.name, me.interface.name), configuration.settings_dict[me.instance.name]['%s_access' % me.interface.name])) ?*/
/*- endif -*/
/*- do register_shared_variable('%s_data' % me.parent.name, 'to_%d_%s_data' % (index, me.interface.name), perm if perm is not none else 'RWX') -*/

/*? macros.dataport_type(me.interface.type) ?*/ * /*? me.interface.name ?*/ =
    (/*? macros.dataport_type(me.interface.type) ?*/ *) & to_/*? index ?*/_/*? me.interface.name ?*/_data;

/*- include 'seL4SharedData-common.template.c' -*/
