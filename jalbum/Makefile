# $NetBSD: Makefile,v 1.10 2005/06/09 17:36:23 marttikuparinen Exp $

DISTNAME=		JAlbum
PKGNAME=		jalbum-5.2
CATEGORIES=		www
MASTER_SITES=		http://www.jalbum.net/download/
EXTRACT_SUFX=		.zip

MAINTAINER=		martti@NetBSD.org
HOMEPAGE=		http://www.jalbum.net/
COMMENT=		Web photo album generator

DIST_SUBDIR=		${PKGNAME_NOREV}-20050609
USE_JAVA=		run
PKG_JVMS_ACCEPTED=	blackdown-jdk13 kaffe sun-jdk13 sun-jdk14 sun-jdk15

do-build:
	${SED}	-e "s#@PKG_JAVA_HOME@#${PKG_JAVA_HOME}#g"	\
		-e "s#@PREFIX@#${PREFIX}#g"			\
		< ${FILESDIR}/jalbum > ${WRKDIR}/jalbum

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/jalbum ${PREFIX}/bin
	(cd ${WRKDIR} && ${PAX} -rw JAlbum) ${PREFIX})

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
