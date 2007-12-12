# $NetBSD: Makefile,v 1.2 2007/12/12 10:27:03 mwdavies Exp $

DISTNAME=	kdeadmin-${_KDE_VERSION}
CATEGORIES=	misc
COMMENT=	System administration tools for the KDE integrated X11 desktop

.include "../../wip/kde4/Makefile.kde4"

# BUILD_MAKE_FLAGS+= VERBOSE=1

.include "../../wip/kde4/kde4.mk"

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../wip/kdelibs4/buildlink3.mk"
.include "../../wip/kdepimlibs4/buildlink3.mk"
.include "../../wip/kdebase-runtime4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
