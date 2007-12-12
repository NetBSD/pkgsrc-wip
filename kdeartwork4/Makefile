# $NetBSD: Makefile,v 1.1.1.1 2007/12/12 03:45:35 mwdavies Exp $

DISTNAME=	kdeartwork-${_KDE_VERSION}
CATEGORIES=	misc
COMMENT=	Artwork for the KDE integrated X11 desktop

.include "../../wip/kde4/Makefile.kde4"

#BUILD_MAKE_FLAGS+= VERBOSE=1

.include "../../wip/kde4/kde4.mk"

.include "../../wip/kdelibs4/buildlink3.mk"
.include "../../wip/kdebase-runtime4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
