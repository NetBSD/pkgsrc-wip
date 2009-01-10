# $NetBSD: Makefile,v 1.2 2009/01/10 10:39:37 mwdavies Exp $

DISTNAME=	kdeplasma-addons-${_KDE_VERSION}
CATEGORIES=	misc
COMMENT=	Plasmoids

.include "../../wip/kde4/Makefile.kde4"

# BUILD_MAKE_FLAGS+= VERBOSE=1

.include "../../wip/kde4/kde4.mk"

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../wip/kdegraphics4/buildlink3.mk"
.include "../../wip/kdelibs4/buildlink3.mk"
.include "../../wip/kdepimlibs4/buildlink3.mk"
.include "../../wip/kdebase-runtime4/buildlink3.mk"
.include "../../wip/kdebase-workspace4/buildlink3.mk"
.include "../../x11/libXcomposite/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
