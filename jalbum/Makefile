# $NetBSD: Makefile,v 1.3 2004/08/03 07:09:53 marttikuparinen Exp $

DISTNAME=		JAlbum
PKGNAME=		jalbum-4.6
CATEGORIES=		www
MASTER_SITES=		http://www.jalbum.net/download/
EXTRACT_SUFX=		.zip

MAINTAINER=		martti@NetBSD.org
HOMEPAGE=		http://www.jalbum.net/
COMMENT=		Web photo album generator

DIST_SUBDIR=		${PKGNAME}
USE_BUILDLINK3=		YES
USE_JAVA2=		YES
USE_JAVA=		run
PKG_JVM_DEFAULT=	sun-jdk

do-build:
	${SED}	-e "s#@PKG_JAVA_HOME@#${PKG_JAVA_HOME}#g"	\
		-e "s#@PREFIX@#${PREFIX}#g"			\
		< ${FILESDIR}/jalbum > ${WRKDIR}/jalbum

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/jalbum ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/JAlbum
	(cd ${WRKDIR} && ${TAR} -cf - JAlbum) | ${TAR} -xf - -C ${PREFIX}

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
