# $NetBSD: Makefile,v 1.2 2003/11/22 17:48:51 mpasternak Exp $
#

DISTNAME=		portaudio_v18_1
PKGNAME=		portaudio-18.1
CATEGORIES=		audio
MASTER_SITES=		http://www.portaudio.com/archives/
EXTRACT_SUFX=		.zip

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://www.portaudio.com/archives/
COMMENT=		Portable cross-platform Audio API 

HAS_CONFIGURE=		YES
USE_GMAKE=		YES
USE_BUILDLINK2=		YES

CONFIGURE_ARGS=		--prefix=${PREFIX}
EXTRACT_CMD=		${LOCALBASE}/bin/unzip -aqo $${extract_file}

pre-configure:
	${CHMOD} 755 ${WRKSRC}/configure

.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/ossaudio.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
