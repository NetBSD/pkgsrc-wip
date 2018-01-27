# $NetBSD: Makefile,v 1.4 2012/10/01 21:43:22 asau Exp $
#

DISTNAME=	basicplayer3.0
PKGNAME=	java-basicplayer-3.0
CATEGORIES=	audio java
MASTER_SITES=	http://www.javazoom.net/jlgui/sources/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.javazoom.net/
COMMENT=	Threaded simple player class based on JavaSound API
LICENSE=	gnu-lgpl-v2.1

WRKSRC=		${WRKDIR}/BasicPlayer3.0

NO_BUILD=	yes
USE_TOOLS+=	pax
USE_LANGUAGES=	# none

USE_JAVA=		yes
PKG_JVMS_ACCEPTED=	sun-jdk6 sun-jdk15 sun-jdk14

INSTALLATION_DIRS=	lib/java share/doc/java-basicplayer

do-install:
	${INSTALL_DATA} ${WRKSRC}/basicplayer3.0.jar\
		${DESTDIR}${PREFIX}/lib/java/basicplayer.jar
	cd ${WRKSRC}/docs && pax -rw -pp . ${DESTDIR}${PREFIX}/share/doc/java-basicplayer


.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
