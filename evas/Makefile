# $NetBSD: Makefile,v 1.28 2008/12/06 14:07:25 minskim Exp $
#

DISTNAME=	evas-0.9.9.050
CATEGORIES=	graphics
MASTER_SITES=	http://download.enlightenment.org/snapshots/2008-09-25/

MAINTAINER=	yazzy@yazzy.org
HOMEPAGE=	http://enlightenment.org/
COMMENT=	Enlightened Canvas Library

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config

PKGCONFIG_OVERRIDE+=	evas-software-16-x11.pc.in
PKGCONFIG_OVERRIDE+=	evas-software-buffer.pc.in
PKGCONFIG_OVERRIDE+=	evas-software-sdl.pc.in
PKGCONFIG_OVERRIDE+=	evas-software-x11.pc.in
PKGCONFIG_OVERRIDE+=	evas-xrender-x11.pc.in
PKGCONFIG_OVERRIDE+=	evas.pc.in

CONFIGURE_ARGS+=	--disable-pthreads --disable-directfb \
			--disable-valgrind --enable-glitz \
			--enable-sdl --enable-image-loader-edb \
			--enable-software-16-x11

PLIST_SUBST=	MODULE_ARCH=${LOWER_OPSYS}${APPEND_ELF}${LOWER_OPSYS_VERSUFFIX}-${NATIVE_LOWER_ARCH}

.include "../../devel/eet/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../databases/edb/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/librsvg/buildlink3.mk"
.include "../../graphics/libungif/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../graphics/glitz/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
