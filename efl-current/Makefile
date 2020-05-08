# $NetBSD: Makefile,v 0.3 2018/09/07 20:03:10 andyb Exp $

DISTNAME=	efl-1.24.0
CATEGORIES=	x11
MASTER_SITES=	https://download.enlightenment.org/rel/libs/efl/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	kikadf.01@gmail.com
HOMEPAGE=	https://enlightenment.org/
COMMENT=	Enlightenment foundation libraries
LICENSE=	2-clause-bsd

MESON_ARGS+=	-Dsystemd=false
MESON_ARGS+=	-Deeze=false
MESON_ARGS+=	-Dpulseaudio=false
MESON_ARGS+=	-Dbuild-tests=false
MESON_ARGS+=	-Dphysics=true
MESON_ARGS+=	-Davahi=true
MESON_ARGS+=	-Dsdl=true

USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++
USE_TOOLS=		pkg-config
LDFLAGS+=		-lcompat
ICON_THEMES=		yes

BUILD_DEPENDS+=		doxygen-[0-9]*:../../devel/doxygen
BUILD_DEPENDS+=		ninja-build-[0-9]*:../../devel/ninja-build

.include "../../audio/libsndfile/buildlink3.mk"
.include "../../converters/fribidi/buildlink3.mk"
.include "../../devel/bullet/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../graphics/giflib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/libraw/buildlink3.mk"
.include "../../graphics/librsvg/buildlink3.mk"
.include "../../graphics/libwebp/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../inputmethod/scim/buildlink3.mk"
.include "../../lang/LuaJIT2/buildlink3.mk"
.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
.include "../../net/avahi/buildlink3.mk"
.include "../../print/libspectre/buildlink3.mk"
.include "../../print/poppler-cpp/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../x11/libXau/buildlink3.mk"
.include "../../x11/libXcomposite/buildlink3.mk"
.include "../../x11/libXdmcp/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libXtst/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
