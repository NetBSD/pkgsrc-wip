
DISTNAME=	payara-${PAYARA_VER}
CATEGORIES=	wip www
MASTER_SITES=	https://s3-eu-west-1.amazonaws.com/payara.fish/Payara+Downloads/Payara+${PAYARA_VER}/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.payara.fish/
COMMENT=	Java EE 7 application server based on GlassFish 4.1
LICENSE=	cddl-1.1 OR (cddl-1.0 AND gnu-gpl-v2)

NO_BUILD=	yes
USE_JAVA=	run
USE_JAVA2=	7
USE_TOOLS+=	pax

.include "../../mk/bsd.prefs.mk"

PAYARA_VER=	4.1.1.164
PAYARA_HOME=	${PREFIX}/share/payara
EGDIR=		${PREFIX}/share/examples/payara
RCD_SCRIPTS=	payara
SMF_NAME=	payara
PAYARA_USER?=	payara
PAYARA_GROUP?=	payara

PAYARA_RUN_DIR=	${VARBASE}/run/${PAYARA_USER}

PKG_GROUPS+=		${PAYARA_GROUP}
PKG_USERS+=		${PAYARA_USER}:${PAYARA_GROUP}
PKG_GROUPS_VARS+=	PAYARA_GROUP
PKG_USERS_VARS+=	PAYARA_USER
PKG_HOME.payara=	${PAYARA_RUN_DIR}
PKG_SHELL.payara=	${SH}


OWN_DIRS=		${PAYARA_HOME} ${PAYARA_RUN_DIR}
OWN_DIRS_PERMS+=	${PAYARA_HOME} ${PAYARA_USER} ${PAYARA_GROUP} 0755 \
			${PAYARA_RUN_DIR} ${PAYARA_USER} ${PAYARA_GROUP} 0755 \

FILES_SUBST+=		JAVA_HOME=${PKG_JAVA_HOME} PAYARA_HOME=${PAYARA_HOME} \
			PAYARA_USER=${PAYARA_USER} PAYARA_GROUP=${PAYARA_GROUP} \
			PAYARA_RUN_DIR=${PAYARA_RUN_DIR}

MESSAGE_SUBST+=		PAYARA_HOME=${PAYARA_HOME}

INSTALLATION_DIRS+=	${PAYARA_HOME}

GLASSFISH_BIN_FILES=	appclient asadmin capture-schema jspc package-appclient schemagen \
			startserv stopserv wscompile wsdeploy wsgen wsimport xjc

BUILD_DEFS+=	VARBASE	
WRKSRC=		${WRKDIR}/payara41

do-install:

	${RUN} ${FIND} ${WRKSRC} -name '*.exe' -delete
	${RUN} ${FIND} ${WRKSRC} -name '*.bat' -delete

	${RUN} cd ${WRKSRC} && ${PAX} -rw -pm . ${DESTDIR}${PAYARA_HOME}

	${RUN} ${FIND} ${DESTDIR}${PAYARA_HOME} -type d -print | \
		${XARGS} ${CHMOD} ${PKGDIRMODE}

	${RUN} ${FIND} ${DESTDIR}${PAYARA_HOME} -type f -print | \
		${XARGS} ${CHMOD} ${SHAREMODE}

	${RUN} ${FIND} ${DESTDIR}${PAYARA_HOME} -type f -name \*.sh -print | \
		${XARGS} ${CHMOD} ${BINMODE}

	${RUN} ${CHMOD} ${BINMODE} ${DESTDIR}${PAYARA_HOME}/bin/*
	${RUN} ${CHMOD} ${BINMODE} ${DESTDIR}${PAYARA_HOME}/mq/bin/*

.for f in ${GLASSFISH_BIN_FILES}
	${RUN} ${CHMOD} ${BINMODE} ${DESTDIR}${PAYARA_HOME}/glassfish/bin/${f}
.endfor


.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
