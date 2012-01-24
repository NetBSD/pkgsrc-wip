# $NetBSD: Makefile,v 1.1 2012/01/24 19:40:55 mwdavies Exp $

DISTNAME=	kdf-${_KDE_VERSION}
CATEGORIES=	sysutils
COMMENT=	show mount points and disk usage under KDE desktop

.include "../../wip/kde4/Makefile.kde4"

.include "../../wip/kde4/kde4.mk"

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../wip/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
