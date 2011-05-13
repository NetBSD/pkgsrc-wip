# $NetBSD: Makefile,v 1.6 2011/05/13 23:25:16 mwdavies Exp $

DISTNAME=	kdeplasma-addons-${_KDE_VERSION}
CATEGORIES=	misc
COMMENT=	Plasmoids

.include "../../wip/kde4/Makefile.kde4"

MAKE_JOBS_SAFE=	no

# BUILD_MAKE_FLAGS+= VERBOSE=1

.include "../../wip/kde4/kde4.mk"

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../wip/kdegraphics4/buildlink3.mk"
BUILDLINK_API_DEPENDS.eigen2+=	eigen2>=2.0.3
.include "../../math/eigen2/buildlink3.mk"
.include "../../misc/attica/buildlink3.mk"
.include "../../wip/kdeedu4/buildlink3.mk"
.include "../../wip/kdepimlibs4/buildlink3.mk"
.include "../../security/qca2/buildlink3.mk"
.include "../../wip/kdelibs4/buildlink3.mk"
.include "../../wip/kdebase-runtime4/buildlink3.mk"
.include "../../wip/kdebase-workspace4/buildlink3.mk"
.include "../../x11/libXcomposite/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
