# $NetBSD: Makefile,v 1.8 2012/01/23 11:38:05 mwdavies Exp $

DISTNAME=	kdeadmin-${_KDE_VERSION}
PKGNAME=	${DISTNAME:S/-4/4-4/}
CATEGORIES=	misc
COMMENT=	System administration tools for the KDE integrated X11 desktop

.include "../../wip/kde4/Makefile.kde4"

# BUILD_MAKE_FLAGS+= VERBOSE=1

REPLACE_PERL+=	knetworkconf/backends/network-conf.cmake
REPLACE_PERL+=	knetworkconf/backends/*.pl.cmake

.include "../../wip/kde4/kde4.mk"

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../wip/kdepimlibs4/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../wip/kdelibs4/buildlink3.mk"
.include "../../wip/kde-runtime4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
