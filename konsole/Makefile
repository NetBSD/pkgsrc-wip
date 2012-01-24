# $NetBSD: Makefile,v 1.2 2012/01/24 18:59:13 mwdavies Exp $

DISTNAME=	konsole-${_KDE_VERSION}
CATEGORIES=	x11
COMMENT=	a terminal emulator for the K Desktop Environment

.include "../../wip/kde4/Makefile.kde4"

.include "../../wip/kde4/kde4.mk"

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../wip/kdelibs4/buildlink3.mk"
.include "../../wip/kde-baseapps4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
