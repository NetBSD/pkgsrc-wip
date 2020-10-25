# $NetBSD$

DISTNAME=	v1.0.9
PKGNAME=	denise-${DISTNAME:S,^v,,}
CATEGORIES=	emulators
MASTER_SITES=	https://bitbucket.org/piciji/denise/get/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	rhialto@NetBSD.org
HOMEPAGE=	https://bitbucket.org/piciji/denise/
COMMENT=	Commodore-64 emulator
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}/piciji-denise-b0f2c4bf4115
USE_LANGUAGES=	c c++	#c++17
USE_TOOLS+=	gmake

.include "../../x11/gtk3/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../audio/pulseaudio/buildlink3.mk"
.include "../../audio/openal-soft/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
