# $NetBSD: Makefile,v 1.1.1.1 2010/09/09 01:23:35 jihbed Exp $
#

DISTNAME=	vorbisspi1.0.3
PKGNAME=	java-vorbisspi-1.0.3
CATEGORIES=	audio java
MASTER_SITES=	http://www.javazoom.net/vorbisspi/sources/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://www.javazoom.net/vorbisspi/
COMMENT=	Java Service Provider Interface for the OGG Vorbis audio format
LICENSE=	gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/VorbisSPI1.0.3
USE_LANGUAGES=	# none

NO_BUILD=		yes
USE_TOOLS+=	pax
USE_LANGUAGES=	# none

USE_JAVA=	yes
PKG_JVMS_ACCEPTED= sun-jdk6 sun-jdk15 sun-jdk14

INSTALLATION_DIRS=	lib/java share/doc/java-vorbisspi

do-install:
	${INSTALL_DATA} ${WRKSRC}/vorbisspi1.0.3.jar\
		${DESTDIR}${PREFIX}/lib/java/vorbisspi.jar
	cd ${WRKSRC}/docs && pax -rw -pp . ${DESTDIR}${PREFIX}/share/doc/java-vorbisspi

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
