# $NetBSD: Makefile,v 1.1.1.1 2007/12/12 03:29:40 mwdavies Exp $

DISTNAME=	kdebase-${_KDE_VERSION}
CATEGORIES=	x11
COMMENT=	Base modules for the KDE 4 integrated X11 desktop

.include "../../wip/kde4/Makefile.kde4"

# BUILD_MAKE_FLAGS+= VERBOSE=1

.include "../../wip/kde4/kde4.mk"

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../wip/qimageblitz/buildlink3.mk"
.include "../../wip/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
