#!/bin/sh

JAVA_HEAP_SIZE=32

@PKG_JAVA_HOME@/bin/java -mx${JAVA_HEAP_SIZE}m -jar @JEDIT_HOME@/jedit.jar $@
