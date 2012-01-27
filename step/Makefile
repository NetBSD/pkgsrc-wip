# $NetBSD: Makefile,v 1.1 2012/01/27 20:27:33 mwdavies Exp $

DISTNAME=	step-${_KDE_VERSION}
CATEGORIES=	misc
COMMENT=	KDE interactive physical simulator

.include "../../wip/kde4/Makefile.kde4"

.include "../../wip/kde4/kde4.mk"

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
BUILDLINK_API_DEPENDS.eigen2+=  eigen2>=2.0.3
.include "../../math/eigen2/buildlink3.mk"
.include "../../math/gsl/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../wip/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
