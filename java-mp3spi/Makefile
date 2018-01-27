# $NetBSD: Makefile,v 1.3 2012/10/01 21:43:22 asau Exp $
#

DISTNAME=	mp3spi1.9.4
PKGNAME=	java-mp3spi-1.9.4
CATEGORIES=	audio java
MASTER_SITES=	http://www.javazoom.net/mp3spi/sources/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.javazoom.net/mp3spi/
COMMENT=	Interface to support MP3 (MPEG 1/2/2.5 Layer 1/2/3) audio format
LICENSE=	gnu-lgpl-v2.1

WRKSRC=		${WRKDIR}/MpegAudioSPI1.9.4

NO_BUILD=	yes
USE_TOOLS+=	pax
USE_LANGUAGES=	# none

USE_JAVA=		yes
PKG_JVMS_ACCEPTED=	sun-jdk6 sun-jdk15 sun-jdk14

INSTALLATION_DIRS=	lib/java share/doc/java-mp3spi

do-install:
	${INSTALL_DATA} ${WRKSRC}/mp3spi1.9.4.jar\
		${DESTDIR}${PREFIX}/lib/java/mp3spi.jar
	cd ${WRKSRC}/doc && pax -rw -pp . ${DESTDIR}${PREFIX}/share/doc/java-mp3spi


.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
