# $NetBSD$

GITHUB_PROJECT=	pcaudiolib
DISTNAME=	pcaudiolib-1.2
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=espeak-ng/}
GITHUB_RELEASE=	1.2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/espeak-ng/pcaudiolib/
COMMENT=	Provides a C API to different audio devices
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

.include "../../mk/oss.buildlink3.mk"
.if ${OSS_TYPE} != "none"
SUBST_CLASSES+=         oss
SUBST_STAGE.oss=        pre-configure
SUBST_FILES.oss=        src/oss.c
SUBST_SED.oss=          -e s,/dev/dsp,${DEVOSSAUDIO},g
SUBST_MESSAGE.oss=      Fixing hardcoded audio device.
.endif

.include "options.mk"
.include "../../mk/bsd.pkg.mk"
