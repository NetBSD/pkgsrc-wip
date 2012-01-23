# $NetBSD: Makefile,v 1.8 2012/01/23 20:50:08 mwdavies Exp $

DISTNAME=	kdetoys-${_KDE_VERSION}
PKGNAME=	${DISTNAME:S/-4/4-4/}
CATEGORIES=	games
COMMENT=	Toys for the KDE integrated X11 desktop

.include "../../wip/kde4/Makefile.kde4"

# BUILD_MAKE_FLAGS+= VERBOSE=1

.include "../../wip/kde4/kde4.mk"

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../wip/kdelibs4/buildlink3.mk"
.include "../../wip/kde-runtime4/buildlink3.mk"
.include "../../wip/kde-workspace4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
