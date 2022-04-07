#!/bin/sh
# blast2go.sh

JAVA=@JAVA_BINPREFIX@-java
JAR=@PREFIX@/libexec/blast2go/blast2go.jar

exec ${JAVA} -jar ${JAR} ${*}
