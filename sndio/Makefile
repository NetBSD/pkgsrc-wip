# $NetBSD$

DISTNAME=	sndio-1.0.1
CATEGORIES=	audio
MASTER_SITES=	http://www.sndio.org/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.sndio.org/
COMMENT=	Small audio and MIDI framework
LICENSE=	isc

HAS_CONFIGURE=	yes

USE_TOOLS+=	gmake

CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--mandir=${PREFIX}/${PKGMANDIR}

.include "../../mk/bsd.pkg.mk"
