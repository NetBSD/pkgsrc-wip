# $NetBSD: Makefile,v 1.2 2005/12/16 14:17:34 marttikuparinen Exp $

DISTNAME=		jave5
PKGNAME=		jave-5.0
CATEGORIES=		editors
MASTER_SITES=		http://www.jave.de/download/ http://www.jave.de/figlet/
DISTFILES=		jave5${EXTRACT_SUFX} figletfonts37${EXTRACT_SUFX}
EXTRACT_SUFX=		.zip

MAINTAINER=		martti@NetBSD.org
HOMEPAGE=		http://www.jave.de/
COMMENT=		Java ASCII Versatile Editor

USE_JAVA=		run
PKG_JVMS_ACCEPTED=	blackdown-jdk13 kaffe sun-jdk13 sun-jdk14 sun-jdk15

WRKSRC=			${WRKDIR}

post-extract:
	${MKDIR} ${WRKDIR}/.workdir
	${MV} ${WRKDIR}/* ${WRKDIR}/.workdir/

do-build:
	${SED}	-e "s#@PKG_JAVA_HOME@#${PKG_JAVA_HOME}#g"	\
		-e "s#@PREFIX@#${PREFIX}#g"			\
		< ${FILESDIR}/jave > ${WRKDIR}/jave

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/jave ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/jave
	(cd ${WRKDIR}/.workdir && ${PAX} -rw * ${PREFIX}/share/jave)

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
