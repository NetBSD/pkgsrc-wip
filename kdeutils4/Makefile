# $NetBSD: Makefile,v 1.3 2008/01/15 11:05:28 mwdavies Exp $

DISTNAME=	kdeutils-${_KDE_VERSION}
CATEGORIES=	misc
COMMENT=	Utilities for the KDE integrated X11 desktop

.include "../../wip/kde4/Makefile.kde4"

# BUILD_MAKE_FLAGS+= VERBOSE=1

BUILDLINK_DEPMETHOD.qt4-tools=	full
.include "../../wip/kde4/kde4.mk"

.include "../../archivers/libzip/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../wip/kdelibs4/buildlink3.mk"
.include "../../wip/kdepimlibs4/buildlink3.mk"
.include "../../wip/kdebase-runtime4/buildlink3.mk"
.include "../../wip/qimageblitz/buildlink3.mk"
.include "../../wip/kdebase-workspace4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
