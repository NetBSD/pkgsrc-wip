# $NetBSD: Makefile,v 1.9 2012/01/24 11:34:45 mwdavies Exp $

DISTNAME=	kdewebdev-${_KDE_VERSION}
PKGNAME=	${DISTNAME:S/-4/4-4/}
CATEGORIES=	www
COMMENT=	HTML editor and tools suitable for experienced web developers

.include "../../wip/kde4/Makefile.kde4"

# BUILD_MAKE_FLAGS+= VERBOSE=1

.include "../../wip/kde4/kde4.mk"

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../wip/kdepimlibs4/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../www/tidy/buildlink3.mk"
.include "../../wip/kdelibs4/buildlink3.mk"
.include "../../wip/kde-runtime4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
