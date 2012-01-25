# $NetBSD: Makefile,v 1.1 2012/01/25 19:19:46 mwdavies Exp $

DISTNAME=	libksane-${_KDE_VERSION}
CATEGORIES=	graphics
COMMENT=	SANE Library interface for KDE

.include "../../wip/kde4/Makefile.kde4"

PKGCONFIG_OVERRIDE+=    libksane.pc.cmake

.include "../../wip/kde4/kde4.mk"

.include "../../graphics/sane-backends/buildlink3.mk"
.include "../../wip/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
