# $NetBSD: Makefile,v 1.1 2012/12/30 19:30:48 roelants Exp $

PKGNAME=	evas-software-x11-${EVAS_VERSION}

COMMENT=	Evas software X11 engine

EVAS_ENGINES=	software-xlib

.include "../../wip/evas/Makefile.common"

BUILD_DIRS=	src/modules/engines/software_x11
MAKE_FLAGS+=	module_la_DEPENDENCIES= \
		module_la_LIBADD="${BUILDLINK_PREFIX.evas}/lib/libevas.la \$$(SOFTWARE_X11_LIBADD)"

INSTALLATION_DIRS+=	lib/pkgconfig
PKGCONFIG_OVERRIDE=	evas-software-x11.pc.in

.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../wip/evas/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../x11/xproto/buildlink3.mk"

post-install:
	${INSTALL_DATA} ${WRKSRC}/evas-software-x11.pc \
		${DESTDIR}${PREFIX}/lib/pkgconfig

.include "../../mk/bsd.pkg.mk"
