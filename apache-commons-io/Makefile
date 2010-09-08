# $NetBSD: Makefile,v 1.1.1.1 2010/09/08 23:29:47 jihbed Exp $
#

DISTNAME=	commons-io-1.4-bin
PKGNAME=	apache-${DISTNAME:S/-bin//}
CATEGORIES=	devel java
MASTER_SITES=	http://apache.multihomed.net//commons/io/binaries/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://commons.apache.org/io/
COMMENT=	Common useful IO related classes
LICENSE=	apache-2.0

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/commons-io-1.4

USE_TOOLS+=	pax
USE_JAVA=	run
NO_BUILD=	yes
USE_LANGUAGES=	# none

INSTALLATION_DIRS=	lib/java share/doc/apache-commons-io

do-install:
	${INSTALL_DATA} ${WRKSRC}/commons-io-1.4.jar \
		${DESTDIR}${PREFIX}/lib/java/commons-io.jar
	cd ${WRKSRC}/docs && pax -rw -pp . ${DESTDIR}${PREFIX}/share/doc/apache-commons-io

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
