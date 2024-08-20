# $NetBSD$

DISTNAME=	lebiniou-version-3.66.0
PKGNAME=	lebiniou-3.66.0
CATEGORIES=	multimedia
MASTER_SITES=	https://gitlab.com/lebiniou/lebiniou/-/archive/version-3.66.0/

MAINTAINER=	pkgsrc-users@NetBSD.org
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

PLIST_VARS+=	alsa v4l2 pulse
.if ${OPSYS} == "Linux"
PLIST.alsa=	yes
.endif
.if ${OPSYS} != "Darwin"
PLIST.v4l2=	yes
PLIST.pulse=	yes
.else
CONFIGURE_ARGS+=	--disable-pulseaudio
.endif

.include "../../audio/jack/buildlink3.mk"
.include "../../audio/liblo/buildlink3.mk"
.if ${OPSYS} != "Darwin"
.include "../../audio/pulseaudio/buildlink3.mk"
.endif
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
