# $NetBSD: Makefile,v 1.5 2012/01/25 10:54:58 mwdavies Exp $

DISTNAME=	gwenview-${_KDE_VERSION}
CATEGORIES=	graphics
COMMENT=	KDE image viewer

.include "../../wip/kde4/Makefile.kde4"

.include "../../wip/kde4/kde4.mk"

.include "../../graphics/exiv2/buildlink3.mk"
.include "../../wip/libkipi/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../wip/kdelibs4/buildlink3.mk"
.include "../../wip/kde-baseapps4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
