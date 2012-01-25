# $NetBSD: Makefile,v 1.1 2012/01/25 09:10:22 mwdavies Exp $

DISTNAME=	printer-applet-${_KDE_VERSION}
CATEGORIES=	print
COMMENT=	KDE printer applet

.include "../../wip/kde4/Makefile.kde4"

PYTHON_VERSIONS_ACCEPTED= 27 26 25
#make sure cmake picks up the same Python version as pkgsrc
CMAKE_ARGS+=	-DPYTHON_EXECUTABLE:FILEPATH=${PYTHONBIN}

REPLACE_PYTHON+=	*.py

.include "../../wip/kde4/kde4.mk"

.include "../../lang/python/application.mk"
.include "../../print/py-cups/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../wip/kdelibs4/buildlink3.mk"
.include "../../wip/py-kde4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
