# $NetBSD: Makefile,v 1.7 2009/03/10 11:36:06 mwdavies Exp $

DISTNAME=	kdeartwork-${_KDE_VERSION}
CATEGORIES=	misc
COMMENT=	Artwork for the KDE integrated X11 desktop

.include "../../wip/kde4/Makefile.kde4"

CMAKE_ARGS+=	-DXSCREENSAVER_CONFIG_DIR:PATH=${BUILDLINK_PREFIX.xscreensaver}/libexec/xscreensaver/config
CMAKE_ARGS+=	-DXSCREENSAVER_DIR:PATH=${BUILDLINK_PREFIX.xscreensaver}/libexec/xscreensaver

#BUILD_MAKE_FLAGS+= VERBOSE=1

PKG_DESTDIR_SUPPORT=	user-destdir

BUILDLINK_API_DEPENDS.xscreensaver+=  xscreensaver>=5.00

.include "../../wip/kde4/kde4.mk"

.include "../../math/eigen2/buildlink3.mk"
.include "../../wip/kdelibs4/buildlink3.mk"
.include "../../wip/kdebase-runtime4/buildlink3.mk"
.include "../../wip/kdebase-workspace4/buildlink3.mk"
.include "../../x11/xscreensaver/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
