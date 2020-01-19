# $NetBSD: Makefile,v 1.3 2012/09/24 16:56:37 asau Exp $
#

DISTNAME=	commons-io-1.4-bin
PKGNAME=	apache-${DISTNAME:S/-bin//}
CATEGORIES=	devel java
MASTER_SITES=	http://apache.multihomed.net//commons/io/binaries/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://commons.apache.org/io/
COMMENT=	Common useful IO related classes
LICENSE=	apache-2.0

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
