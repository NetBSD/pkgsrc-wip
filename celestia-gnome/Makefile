# $NetBSD: Makefile,v 1.2 2003/05/08 23:23:35 lsed Exp $
#

.include "../../wip/celestia/Makefile.common"

PKGNAME=	${DISTNAME:S/-/-gnome-/}

COMMENT=	GNOME frontend for free real-time 3D space simulator

DEPENDS=	celestia-${CELESTIA_VERS}:../../wip/celestia

CONFIGURE_ARGS+=	--with-gnome
CONFIGURE_ARGS+=	--without-kde

BUILD_DIRS=	${WRKSRC}/src

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/celestia/celestia ${PREFIX}/bin/gcelestia

.include "../../graphics/glut/buildlink2.mk"
.include "../../x11/gnome-libs/buildlink2.mk"
.include "../../x11/gtkglarea/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
