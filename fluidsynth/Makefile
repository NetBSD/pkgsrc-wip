# $NetBSD: Makefile,v 1.3 2005/02/18 14:12:37 bencollver Exp $
#

DISTNAME=		fluidsynth-1.0.5
CATEGORIES=		audio
MASTER_SITES=		http://savannah.nongnu.org/download/fluid/

MAINTAINER=		ben@NetBSD.org
HOMEPAGE=		http://www.fluidsynth.org/
COMMENT=		Software synthesizer based on SoundFont2

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=		YES
USE_BUILDLINK3=		YES

CFLAGS+=		-DDEVOSSAUDIO="\"${DEVOSSAUDIO}\""
LDFLAGS+=		${LIBOSSAUDIO}

.include "../../devel/readline/buildlink3.mk"
.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
