# $NetBSD: Makefile,v 1.1 2012/01/23 10:11:29 mwdavies Exp $

DISTNAME=	libkexiv2-${_KDE_VERSION}
CATEGORIES=	graphics
COMMENT=	a KDE wrapper around exiv2

.include "../../wip/kde4/Makefile.kde4"

PKGCONFIG_OVERRIDE+=    libkexiv2.pc.cmake

.include "../../wip/kde4/kde4.mk"

.include "../../graphics/exiv2/buildlink3.mk"
.include "../../wip/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
