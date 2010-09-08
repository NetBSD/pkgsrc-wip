# $NetBSD: Makefile,v 1.1.1.1 2010/09/08 21:18:04 jihbed Exp $
#

DISTNAME=	commons-collections-3.2.1-bin
PKGNAME=	java-${DISTNAME:S/-bin//}
CATEGORIES=	devel java
MASTER_SITES=	http://www.motorlogy.com/apachemirror//commons/collections/binaries/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://commons.apache.org/collections/
COMMENT=	Set of abstract data type interfaces and implementations
LICENSE=	apache-2.0

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/commons-collections-3.2.1

NO_BUILD=		yes
USE_TOOLS+=	pax
USE_LANGUAGES=	# none

USE_JAVA=	run

INSTALLATION_DIRS=	lib/java share/doc/java-commons-collections

do-install:
	${INSTALL_DATA} ${WRKSRC}/commons-collections-3.2.1.jar\
		${DESTDIR}${PREFIX}/lib/java/commons-collections.jar
	${INSTALL_DATA} ${WRKSRC}/commons-collections-testframework-3.2.1.jar\
		${DESTDIR}${PREFIX}/lib/java/commons-collections-testframework.jar
	cd ${WRKSRC}/apidocs && pax -rw -pp . ${DESTDIR}${PREFIX}/share/doc/java-commons-collections


.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
