/*
   +----------------------------------------------------------------------+
   | PHP Version 5                                                        |
   +----------------------------------------------------------------------+
   | Copyright (c) 1997-2013 The PHP Group                                |
   +----------------------------------------------------------------------+
   | This source file is subject to version 3.01 of the PHP license,      |
   | that is bundled with this package in the file LICENSE, and is        |
   | available through the world-wide-web at the following url:           |
   | http://www.php.net/license/3_01.txt                                  |
   | If you did not receive a copy of the PHP license and are unable to   |
   | obtain it through the world-wide-web, please send a note to          |
   | license@php.net so we can mail you a copy immediately.               |
   +----------------------------------------------------------------------+
   | Authors: Felipe Pena <felipe@php.net>                                |
   | Authors: Joe Watkins <joe.watkins@live.co.uk>                        |
   +----------------------------------------------------------------------+
*/

#include <stdio.h>
#include "zend.h"
#include "phpdbg.h"
#include "phpdbg_help.h"

PHPDBG_HELP(exec) /* {{{ */
{
	printf("Will attempt execution, if compilation has not yet taken place, it occurs now.\n");
	printf("The execution context must be set before execution can take place\n");
	return SUCCESS;
} /* }}} */

PHPDBG_HELP(step) /* {{{ */
{
    printf("You can enable and disable stepping at any phpdbg prompt during execution\n");
    printf("For example:\n");
    printf("\tphpdbg> stepping 1\n");
    printf("Will enable stepping\n");
    printf("While stepping is enabled you are presented with a prompt after the execution of each opcode\n");
    return SUCCESS;
} /* }}} */

PHPDBG_HELP(next) /* {{{ */
{
	printf("While stepping through execution, or after a breakpoint, use the next command to step back into the vm and execute the next opcode\n");
	return SUCCESS;
} /* }}} */

PHPDBG_HELP(compile) /* {{{ */
{
	printf("Pre-compilation of the execution context provides the opportunity to inspect the opcodes before they are executed\n");
	printf("The execution context must be set for compilation to succeed\n");
	printf("If errors occur during compilation they must be resolved before execution can take place.\n");
	printf("It is a good idea to clean the environment between each compilation with the clean command\n");
	printf("You do not need to exit phpdbg to retry compilation\n");
	return SUCCESS;
} /* }}} */

PHPDBG_HELP(print) /* {{{ */
{
	printf("By default, print will show information about the current execution environment\n");
	printf("To show specific information pass an expression to print, for example:\n");
	printf("\tphpdbg> print opcodes[0]\n");
	printf("Will show the opline @ 0\n");
	printf("Available print commands:\n");
	printf("\tNone\n");
	return SUCCESS;
} /* }}} */

PHPDBG_HELP(run) /* {{{ */
{
	printf("Run the code inside the debug vm, you should have break points and variables set before running\n");
	printf("The execution context must not be set, but not necessarily compiled before execution occurs\n");
	return SUCCESS;
} /* }}} */

PHPDBG_HELP(eval) /* {{{ */
{
	printf("Access to eval() allows you to change the environment during execution, careful though !!\n");
	printf("Note: When using eval in phpdbg do not prefix the code with return.\n");
	return SUCCESS;
} /* }}} */

PHPDBG_HELP(break) /* {{{ */
{
	printf("Setting a breakpoint stops execution at a specific stage, the syntax is:\n");
	printf("\tfile:line\n");
	printf("\tfunction\n");
	printf("\t\\my\\class::method\n");
	printf("\t0x16\n");
	printf("For example:\n");
	printf("\tphpdbg> break test.php:1\n");
	printf("Will break execution on line 1 of test.php\n");
	printf("\tphpdbg> break my_function\n");
	printf("Will break execution on entry to my_function\n");
	printf("\tphpdbg> break \\my\\class::method\n");
	printf("Will break execution on entry to \\my\\class::method\n");
	printf("\tphpdbg> break 0x7ff68f570e08\n");
	printf("Will break at the opline with the address provided (addresses are shown during execution)\n");
	printf("It is important to note, an address is only valid for the current compiled representation of the script\n");
	printf("If you have to clean the environment and recompile then your opline break points will be invalid\n");
	return SUCCESS;
} /* }}} */

PHPDBG_HELP(clean) /* {{{ */
{
    printf("While debugging you may experience errors because of attempts to redeclare classes, constants or functions.\n");
    printf("Cleaning the environment cleans these tables, so that files can be recompiled without exiting phpdbg.\n");
    return SUCCESS;
} /* }}} */

PHPDBG_HELP(clear) /* {{{ */
{
    printf("Clearing breakpoints means you can once again run code without interruption\n");
    printf("Careful though, all breakpoints are lost; be sure debugging is complete before clearing\n");
    return SUCCESS;
} /* }}} */

PHPDBG_HELP(quiet) /* {{{ */
{
    printf("Setting quietness on will stop the OPLINE output during execution\n");
    printf("For example:\n");
    printf("\tphpdbg> quiet 1\n");
    printf("Will silence OPLINE output, while\n");
    printf("\tphpdbg> quiet 0\n");
    printf("Will enable OPLINE output again\n");
    return SUCCESS;
} /* }}} */

PHPDBG_HELP(back) /* {{{ */
{
	printf("The backtrace is gathered with the default debug_backtrace functionality.\n");
	printf("You can set the limit on the trace, for example:\n");
	printf("\tphpdbg> back 5\n");
	printf("Will limit the number of frames to 5, the default is no limit\n");
	return SUCCESS;
} /* }}} */

PHPDBG_HELP(list) /* {{{ */
{
	printf("The list command displays N line from current context file.\n");
	printf("\tphpdbg> list 2\n");
	printf("Will print next 2 lines from the current file\n");
	printf("\tphpdbg> list func\n");
	printf("Will print the source of the global function \"func\"\n");
	printf("\tphpdbg> list .mine\n");
	printf("Will print the source of the class method \"mine\"\n");
	printf("Note: before listing functions you must have a populated function table, try compile !!\n");
	return SUCCESS;
} /* }}} */
