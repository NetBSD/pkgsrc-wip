# $NetBSD: Makefile,v 1.3 2009/03/01 11:24:04 guigui2 Exp $
#

DISTNAME=		tint-0.6.0
CATEGORIES=		x11
MASTER_SITES=		http://tint2.googlecode.com/files/

MAINTAINER=		netbsd@guigui2.net
HOMEPAGE=		http://tint2.googlecode.com/
COMMENT=		Tint2 is a simple panel/taskbar

USE_TOOLS+=		gmake pkg-config
WRKSRC=			${WRKDIR}/tint/src
BUILD_TARGET=		tint

PKG_SYSCONFSUBDIR=	xdg
CONF_FILES+=		${PREFIX}/share/examples/xdg/tint/tintrc \
			${PKG_SYSCONFDIR}/tintrc

AUTO_MKDIRS=		yes

post-install:
	${INSTALL_DATA} ${WRKDIR}/tint/doc/tint-0.6.* ${PREFIX}/share/doc/tint/

.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/imlib2/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
