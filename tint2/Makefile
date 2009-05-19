# $NetBSD: Makefile,v 1.5 2009/05/19 09:00:13 thomasklausner Exp $
#

DISTNAME=		tint-0.6.0
CATEGORIES=		x11
MASTER_SITES=		http://tint2.googlecode.com/files/

MAINTAINER=		netbsd@guigui2.net
HOMEPAGE=		http://tint2.googlecode.com/
COMMENT=		Tint2 is a simple panel/taskbar
LICENSE=		gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		gmake pkg-config
WRKSRC=			${WRKDIR}/tint/src
PKG_SYSCONFSUBDIR=	xdg
CONF_FILES+=		${PREFIX}/share/examples/xdg/tint/tintrc \
			${PKG_SYSCONFDIR}/tintrc
INSTALLATION_DIRS=	${PREFIX}/share/doc/tint

BUILD_TARGET=		tint

post-install:
			${INSTALL_DATA} ${WRKDIR}/tint/doc/tint-0.6.* \
				${DESTDIR}${PREFIX}/share/doc/tint/

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/imlib2/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
