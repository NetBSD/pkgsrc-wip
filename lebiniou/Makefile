# $NetBSD$

DISTNAME=	lebiniou-version-3.66.0
PKGNAME=	lebiniou-3.66.0
CATEGORIES=	multimedia
MASTER_SITES=	https://gitlab.com/lebiniou/lebiniou/-/archive/version-3.66.0/

MAINTAINER=	olivier@biniou.info
HOMEPAGE=	https://biniou.net/
COMMENT=	User-friendly, powerful music visualization / VJing tool
LICENSE=	gnu-gpl-v2

USE_LIBTOOL=	yes
USE_TOOLS+=	autoconf automake autoreconf pkg-config
GNU_CONFIGURE=	yes

DEPENDS+=	lebiniou-data>=3.66.0:../../wip/lebiniou-data
DEPENDS+=	xdg-utils>=1.1.3:../../misc/xdg-utils

pre-configure:
	set -e; cd ${WRKSRC} && ./bootstrap

.include "../../mk/bsd.prefs.mk"

PLIST_VARS+=	alsa
.if ${OPSYS} == "Linux"
PLIST.alsa=	yes
.endif

.include "../../audio/jack/buildlink3.mk"
.include "../../audio/liblo/buildlink3.mk"
.include "../../audio/pulseaudio/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/libcaca/buildlink3.mk"
.include "../../graphics/ImageMagick/buildlink3.mk"
.include "../../math/fftw/buildlink3.mk"
.include "../../multimedia/ffmpeg5/buildlink3.mk"
.include "../../textproc/jansson/buildlink3.mk"
.include "../../wip/orcania/buildlink3.mk"
.include "../../wip/sndio/buildlink3.mk"
.include "../../wip/ulfius/buildlink3.mk"
.include "../../wip/yder/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
