# $NetBSD$

DISTNAME=	rubberband-1.8.1
CATEGORIES=	audio
MASTER_SITES=	http://code.breakfastquay.com/attachments/download/34/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.rog
HOMEPAGE=	http://code.breakfastquay.com/attachments/download/34/
COMMENT=	Audio time-stretching and pitch-shifting library
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config gmake
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	rubberband.pc.in

.include "../../audio/ladspa/buildlink3.mk"
.include "../../wip/vamp-plugin-sdk/buildlink3.mk"
.include "../../math/fftw/buildlink3.mk"
.include "../../audio/libsamplerate/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
