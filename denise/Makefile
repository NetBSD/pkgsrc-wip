# $NetBSD$

DISTNAME=	v1.1.3.1
PKGNAME=	denise-${DISTNAME:S,^v,,}
CATEGORIES=	emulators
MASTER_SITES=	https://bitbucket.org/piciji/denise/get/
DIST_SUBDIR=	denise
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	rhialto@NetBSD.org
HOMEPAGE=	https://bitbucket.org/piciji/denise/
COMMENT=	Commodore-64 emulator
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}/piciji-denise-c592258703c8
USE_LANGUAGES=	c c++17
USE_TOOLS+=	gmake pkg-config

SUBST_CLASSES+=		path
SUBST_STAGE.path=	post-configure
SUBST_MESSAGE.path=	Fixing reference to installation path
SUBST_FILES.path+=	guikit/gtk/tools.cpp
SUBST_SED.path=		-e "s;/usr/pkg;${PREFIX};"

.include "../../x11/gtk3/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../audio/pulseaudio/buildlink3.mk"
.include "../../audio/openal-soft/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
