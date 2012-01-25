# $NetBSD: Makefile,v 1.1 2012/01/25 10:54:58 mwdavies Exp $

DISTNAME=	libkipi-${_KDE_VERSION}
CATEGORIES=	graphics
COMMENT=	KDE image plugin interface

.include "../../wip/kde4/Makefile.kde4"

PKGCONFIG_OVERRIDE+=    libkipi.pc.cmake

.include "../../wip/kde4/kde4.mk"

.include "../../wip/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
