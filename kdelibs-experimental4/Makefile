# $NetBSD: Makefile,v 1.1 2009/07/30 12:08:27 mwdavies Exp $

DISTNAME=	kdelibs-experimental-${_KDE_VERSION}
CATEGORIES=	x11
COMMENT=	Experimental libraries for the KDE integrated X11 desktop

.include "../../wip/kde4/Makefile.kde4"

PKG_DESTDIR_SUPPORT=	user-destdir

# BUILD_MAKE_FLAGS+= VERBOSE=1

.include "../../wip/kde4/kde4.mk"

.include "../../wip/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
