# $NetBSD: Makefile,v 1.7 2008/03/26 05:35:35 bsadewitz Exp $

DISTNAME=	cairo-1.5.12
CATEGORIES=	graphics
MASTER_SITES=	http://cairographics.org/snapshots/

MAINTAINER=	recht@NetBSD.org
HOMEPAGE=	http://cairographics.org/
COMMENT=	Vector graphics library with cross-device output support

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES+=		c99 c++
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		pkg-config
PKGCONFIG_OVERRIDE+=	src/cairo.pc.in src/cairo-backend.pc.in
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-xcb
CONFIGURE_ARGS+=	--enable-glitz
CONFIGURE_ARGS+=	--enable-pdf
CONFIGURE_ARGS+=	--enable-ps

.if exists(/System/Library/Frameworks/Carbon.framework)
CONFIGURE_ARGS+=	--enable-quartz
CONFIGURE_ARGS+=	--enable-atsui
PLIST_SUBST+=		CARBON=
.else
PLIST_SUBST+=		CARBON="@comment "
.endif

.include "../../graphics/cairo/options.mk"
DESCR_SRC=		${.CURDIR}/../../graphics/cairo/DESCR

BUILDLINK_API_DEPENDS.glitz+=	glitz>=0.5.1

# For snprintf()
CPPFLAGS.SunOS+=		-D__EXTENSIONS__

TEST_TARGET=			check

.include "../../devel/zlib/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/glitz/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../x11/pixman/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
