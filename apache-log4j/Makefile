# $NetBSD: Makefile,v 1.1.1.1 2010/09/09 01:47:48 jihbed Exp $
#

DISTNAME=	apache-log4j-1.2.16
CATEGORIES=	www java
MASTER_SITES=	http://apache.multihomed.net//logging/log4j/1.2.16/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://apache.multihomed.net//logging/log4j/1.2.16/
COMMENT=	Logging facility for Java
LICENSE=	apache-2.0

PKG_DESTDIR_SUPPORT=	user-destdir

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
