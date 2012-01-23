# $NetBSD: Makefile,v 1.1 2012/01/23 10:07:35 mwdavies Exp $

DISTNAME=	kde-wallpapers-${_KDE_VERSION}
PKGNAME=	${DISTNAME:S/-4/4-4/}
CATEGORIES=	misc
COMMENT=	Wallpapers for the KDE integrated X11 desktop

.include "../../wip/kde4/Makefile.kde4"

.include "../../wip/kde4/kde4.mk"

.include "../../wip/kdelibs4/buildlink3.mk"
.include "../../wip/kde-runtime4/buildlink3.mk"
.include "../../wip/kde-workspace4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
