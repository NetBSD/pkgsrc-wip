# $NetBSD$

DISTNAME=	sayonara-1.11.0_stable1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITLAB:=luciocarreras/}
GITLAB_PROJECT=	sayonara-player
GITLAB_TAG=	${PKGVERSION_NOREV:S/_/-/}

MAINTAINER=	kikadf.01@gmail.com
HOMEPAGE=	https://www.sayonara-player.com/
COMMENT=	Highly customizable, clear and fast audio player
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++
WRKSRC=		${WRKDIR}/${GITLAB_PROJECT}-${GITLAB_TAG}

REPLACE_PYTHON+=	src/DBus/sayonara-ctl
REPLACE_PYTHON+=	src/DBus/sayonara-query

DEPENDS+=	gst-plugins1-flac-[0-9]*:../../audio/gst-plugins1-flac
DEPENDS+=	gst-plugins1-mpg123-[0-9]*:../../audio/gst-plugins1-mpg123
DEPENDS+=	gst-plugins1-ogg-[0-9]*:../../multimedia/gst-plugins1-ogg
DEPENDS+=	gst-plugins1-opus-[0-9]*:../../audio/gst-plugins1-opus
DEPENDS+=	gst-plugins1-vorbis-[0-9]*:../../audio/gst-plugins1-vorbis
DEPENDS+=	gst-plugins1-vorbis-[0-9]*:../../audio/gst-plugins1-soundtouch

.include "../../mk/bsd.prefs.mk"
.include "../../mk/oss.buildlink3.mk"

.if ${OPSYS} == "Linux"
DEPENDS+=	gst-plugins1-alsa-[0-9]*:../../audio/gst-plugins1-alsa
.else
.  if ${OSS_TYPE} != "none"
DEPENDS+=	gst-plugins1-oss-[0-9]*:../../audio/gst-plugins1-oss
.  endif
.endif

.include "../../devel/cmake/build.mk"
.include "../../audio/taglib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../multimedia/gstreamer1/buildlink3.mk"
.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
.include "../../multimedia/gst-plugins1-good/buildlink3.mk"
.include "../../multimedia/gst-plugins1-bad/buildlink3.mk"
.include "../../x11/qt5-qtsvg/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
