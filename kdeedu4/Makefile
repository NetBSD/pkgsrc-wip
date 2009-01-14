# $NetBSD: Makefile,v 1.9 2009/01/14 10:51:54 mwdavies Exp $

DISTNAME=	kdeedu-${_KDE_VERSION}
CATEGORIES=	misc
COMMENT=	Edu{tainment,cation} tools for the KDE integrated X11 desktop

.include "../../wip/kde4/Makefile.kde4"

# BUILD_MAKE_FLAGS+= VERBOSE=1

PKG_DESTDIR_SUPPORT=    user-destdir

CMAKE_ARGS+=	-DBUILD_kmplot:BOOL=OFF
CMAKE_ARGS+=	-DWITH_SBIG:BOOL=OFF
# CMAKE_ARGS+=	-DWITH_PyKDE4:BOOL=OFF   # "sip: MarblePlacemarkModel is undefined"

USE_GNU_READLINE=	yes
BROKEN_READLINE_DETECTION=	yes

.include "../../wip/kde4/kde4.mk"

.include "../../lang/python/application.mk"
.include "../../devel/boost-python/buildlink3.mk"
.include "../../devel/cfitsio/buildlink3.mk"
.include "../../devel/libusb/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../wip/kdelibs4/buildlink3.mk"
.include "../../wip/kdebase-runtime4/buildlink3.mk"
.include "../../wip/kdebase-workspace4/buildlink3.mk"
.include "../../wip/kdebindings4-python/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
