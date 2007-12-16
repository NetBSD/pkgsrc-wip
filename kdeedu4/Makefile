# $NetBSD: Makefile,v 1.2 2007/12/16 19:49:56 mwdavies Exp $

DISTNAME=	kdeedu-${_KDE_VERSION}
CATEGORIES=	misc
COMMENT=	Edu{tainment,cation} tools for the KDE integrated X11 desktop

.include "../../wip/kde4/Makefile.kde4"

# BUILD_MAKE_FLAGS+= VERBOSE=1

CMAKE_ARGS+=	-DBUILD_kmplot:BOOL=OFF

USE_GNU_READLINE=	yes
BROKEN_READLINE_DETECTION=	yes

.include "../../wip/kde4/kde4.mk"

.include "../../devel/libusb/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../wip/kdelibs4/buildlink3.mk"
.include "../../wip/kdebase-runtime4/buildlink3.mk"
#.include "../../wip/qimageblitz/buildlink3.mk"
#.include "../../wip/kdebase-workspace4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
