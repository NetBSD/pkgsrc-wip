# $NetBSD: Makefile,v 1.15 2011/05/13 23:25:15 mwdavies Exp $

DISTNAME=	kdeedu-${_KDE_VERSION}
CATEGORIES=	misc
COMMENT=	Edu{tainment,cation} tools for the KDE integrated X11 desktop

.include "../../wip/kde4/Makefile.kde4"

# BUILD_MAKE_FLAGS+= VERBOSE=1

CMAKE_ARGS+=	-DBUILD_kmplot:BOOL=OFF
CMAKE_ARGS+=	-DWITH_SBIG:BOOL=OFF
CMAKE_ARGS+=	-DWITH_R:BOOL=OFF
# CMAKE_ARGS+=	-DWITH_PyKDE4:BOOL=OFF   # "sip: MarblePlacemarkModel is undefined"
#XXX detection does not work reliably
CMAKE_ARGS+=	-DWITH_BoostPython:BOOL=OFF

USE_GNU_READLINE=	yes
BROKEN_READLINE_DETECTION=	yes

REPLACE_PYTHON+=	kig/pykig/pykig.py

.include "../../wip/kde4/kde4.mk"

#.include "../../lang/python/application.mk"
#.include "../../devel/boost-python/buildlink3.mk"
.include "../../devel/cfitsio/buildlink3.mk"
.include "../../devel/libusb/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/python/application.mk"
BUILDLINK_API_DEPENDS.eigen2+=	eigen2>=2.0.3
.include "../../math/eigen2/buildlink3.mk"
.include "../../math/gsl/buildlink3.mk"
.include "../../print/libspectre/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../wip/kdelibs4/buildlink3.mk"
.include "../../wip/kdebase-runtime4/buildlink3.mk"
.include "../../wip/kdebase-workspace4/buildlink3.mk"
.include "../../wip/kdebindings4-python/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
