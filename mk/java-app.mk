# This file needs more work
# @author: pancake<pancake@phreaker.net>
# 
# JAVA_APP_TARGETS  All target names space separated
#
# JAVA_APP_PATH     Path to install java applications (${PREFIX}/bin by default)
#
# JAVA_APP_BIN.x    name of target executable (target name is default)
#
# JAVA_APP_MAIN.x   class name to execute (manifest in CLASSPATH by default)
#
# JAVA_APP_CLASSPATH.x default classpath for this java application
#
# TODO:
#  better documentation
#  add jar dependencies with bl3
#  check JAVA_APP_CLASSPATH when no JAVA_APP_MAIN defined.
#  80 cols width

.if !defined(JAVA_APP_MK)
JAVA_APP_MK=		# defined

JAR_MAIN_PREFIX?=	share/classpath
JAR_PREFIX?=		${LOCALBASE}/${JAR_MAIN_PREFIX}

PLIST_SUBST+=		JAR_MAIN_PREFIX=${JAR_MAIN_PREFIX}
BUILD_DEFS+=		JAR_MAIN_PREFIX

# default
JAVA_APP_PATH?=		${PREFIX}/bin
JAVA_APP_WRKDIR?=	${WRKDIR}/.java-app

# main loop
.for s in ${JAVA_APP_TARGETS}

.PHONY:		install-java-app-${s}
post-install: 	install-java-app-${s}

.PHONY:		build-java-app-${s}
post-configure:	build-java-app-${s}

JAVA_APP_PATH.${s}?=	${JAVA_APP_PATH}
JAVA_APP_BIN.${s}?=	${s}

build-java-app-${s}:
	${MKDIR} ${JAVA_APP_WRKDIR}
	@${ECHO} "#!/bin/sh" > ${JAVA_APP_WRKDIR}/${JAVA_APP_BIN.${s}}
.if defined(JAVA_APP_MAIN.${s})
	@${ECHO} "env CLASSPATH=${JAVA_APP_CLASSPATH.${s}} java ${JAVA_APP_MAIN.${s}} \$$*" \
	>> ${JAVA_APP_WRKDIR}/${JAVA_APP_BIN.${s}}
.else
	@${ECHO} "java -jar ${JAVA_APP_CLASSPATH} \$$*" \
	>> ${JAVA_APP_WRKDIR}/${JAVA_APP_BIN.${s}}
.endif

install-java-app-${s}:
	${INSTALL_SCRIPT} ${JAVA_APP_WRKDIR}/${JAVA_APP_BIN.${s}} ${JAVA_APP_PATH}

.endfor
.undef s

.PHONY:		install-required-dirs
pre-install:	install-required-dirs

install-required-dirs:
.if !exists(${JAVA_APP_CLASSPATH})
	${INSTALL_DATA_DIR} ${JAVA_APP_CLASSPATH}
.endif
.if !exists(${JAR_PREFIX})
	${INSTALL_DATA_DIR} ${JAR_PREFIX}
.endif

.endif # JAVA_APP_MK
