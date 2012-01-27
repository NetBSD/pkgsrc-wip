# $NetBSD: Makefile,v 1.1 2012/01/27 21:33:31 mwdavies Exp $

DISTNAME=	kig-${_KDE_VERSION}
CATEGORIES=	misc
COMMENT=	KDE interactive geometry

.include "../../wip/kde4/Makefile.kde4"

REPLACE_PYTHON+=	pykig/pykig.py

.include "../../wip/kde4/kde4.mk"

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../wip/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
