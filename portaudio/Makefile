# $NetBSD: Makefile,v 1.6 2004/04/08 18:15:34 bencollver Exp $
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
USE_GNU_TOOLS+=		make
USE_BUILDLINK3=		YES

CONFIGURE_ARGS=		--prefix=${PREFIX}
EXTRACT_CMD_OPTS.zip=	-aqo

pre-configure:
	${CHMOD} 755 ${WRKSRC}/configure

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
