# $NetBSD: Makefile,v 1.4 2003/12/30 23:33:26 cjep Exp $
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
EXTRACT_CMD_OPTS.zip=	-aqo

pre-configure:
	${CHMOD} 755 ${WRKSRC}/configure

.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/ossaudio.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
