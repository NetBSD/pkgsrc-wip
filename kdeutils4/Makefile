# $NetBSD: Makefile,v 1.10 2009/01/10 20:21:39 mwdavies Exp $

DISTNAME=	kdeutils-${_KDE_VERSION}
CATEGORIES=	misc
COMMENT=	Utilities for the KDE integrated X11 desktop

.include "../../wip/kde4/Makefile.kde4"

#make sure cmake picks up the same Python version as pkgsrc
CMAKE_ARGS+=	-DPYTHON_EXECUTABLE:FILEPATH=${PYTHONBIN}

# BUILD_MAKE_FLAGS+= VERBOSE=1

BUILDLINK_DEPMETHOD.qt4-tools=	full
.include "../../wip/kde4/kde4.mk"

.include "../../archivers/libarchive/buildlink3.mk"
.include "../../archivers/libzip/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/qimageblitz/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../wip/kdebindings4-python/buildlink3.mk"
.include "../../print/py-cups/buildlink3.mk"
.include "../../wip/kdelibs4/buildlink3.mk"
.include "../../wip/kdepimlibs4/buildlink3.mk"
.include "../../wip/kdebase-runtime4/buildlink3.mk"
.include "../../wip/kdebase-workspace4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
