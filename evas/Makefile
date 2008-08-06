# $NetBSD: Makefile,v 1.21 2008/08/06 13:55:13 yazzy Exp $
#

DISTNAME=	evas-0.9.9.043
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://download.enlightenment.org/snapshots/2008-05-19/ \
		http://www.ezunix.org/pkgsrc/e17/snapshots/2008-05-19/ \
                http://jfranz.users.bsdprojects.net/pkgsrc/e17/

MAINTAINER=	yazzy@yazzy.org
HOMEPAGE=	http://enlightenment.org/
COMMENT=	Enlightened Canvas Library

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS=	gmake pkg-config

CONFIGURE_ARGS+=	--disable-pthreads --disable-directfb \
			--disable-valgrind --enable-glitz \
			--enable-sdl --enable-image-loader-edb \
			--enable-software-16-x11

.include "../../wip/eet/buildlink3.mk"
.include "../../wip/libxcb/buildlink3.mk"
.include "../../wip/xcb-proto/buildlink3.mk"
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
