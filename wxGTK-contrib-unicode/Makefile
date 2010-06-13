# $NetBSD: Makefile,v 1.5 2010/06/13 22:47:21 thomasklausner Exp $
#

.include "../../wip/wxGTK-unicode/Makefile.common"

PKGNAME=		${DISTNAME:S/wxGTK/wxGTK-contrib-unicode/}
PKGREVISION=		1
MAINTAINER=		milos.negovanovic@googlemail.com
COMMENT=		GTK-based unicode implementation of the wxWidgets GUI library (contrib libraries)

USE_TOOLS+=		gmake

# conflicts with non unicode version
CONFLICTS+=		wxGTK-contrib-[0-9]*

do-build:
	cd ${WRKSRC}/contrib/src && ${SETENV} ${MAKE_ENV} ${MAKE} ${BUILD_MAKE_FLAGS}

do-install:
	cd ${WRKSRC}/contrib/src && ${SETENV} ${MAKE_ENV} ${MAKE} install ${INSTALL_MAKE_FLAGS}

.include "../../wip/wxGTK-unicode/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
