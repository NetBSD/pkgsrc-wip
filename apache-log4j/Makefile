# $NetBSD: Makefile,v 1.3 2012/09/24 16:56:38 asau Exp $
#

DISTNAME=	apache-log4j-1.2.16
CATEGORIES=	www java
MASTER_SITES=	http://apache.multihomed.net//logging/log4j/1.2.16/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://apache.multihomed.net//logging/log4j/1.2.16/
COMMENT=	Logging facility for Java
LICENSE=	apache-2.0

NO_BUILD=	yes
USE_JAVA=	run
USE_TOOLS+=	pax
USE_LANGUAGES=	c++

EDGDIR=	${PREFIX}/share/examples/apache-log4j

INSTALLATION_DIRS=	lib/java share/doc/apache-log4j ${EDGDIR}

do-install:
	${INSTALL_DATA} ${WRKSRC}/log4j-1.2.16.jar ${DESTDIR}${PREFIX}/lib/java/log4j.jar
	cd ${WRKSRC}/site&& pax -rwpe . ${DESTDIR}${PREFIX}/share/doc/apache-log4j
	cd ${WRKSRC}/examples && pax -rw -pe . ${DESTDIR}${EDGDIR}

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
