# $NetBSD: Makefile,v 1.7 2014/01/26 15:49:50 thomasklausner Exp $

DISTNAME=	arandr-0.1.4
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	http://christian.amsuess.com/tools/arandr/files/

MAINTAINER=	rga@sdf.lonestar.org
HOMEPAGE=	http://christian.amsuess.com/tools/arandr/
COMMENT=	Designed to provide a simple visual front end for XRandR 1.2/1.3
LICENSE=	gnu-gpl-v3

DEPENDS+=       ${PYPKGPREFIX}-docutils>=0.6:../../textproc/py-docutils
DEPENDS+=	xrandr>=1.2:../../x11/xrandr

PY_PATCHPLIST = YES
PYSETUP = setup.py
PYTHON_VERSIONS_INCOMPATIBLE=	33 # py-gtk2, py-docutils

# Adjust setup.py
SUBST_CLASSES+=         setup
SUBST_STAGE.setup=      pre-configure
SUBST_MESSAGE.setup=    Fixing ${PYSETUP}
SUBST_FILES.setup=      ${PYSETUP}
SUBST_SED.setup+=       -e 's,share/man/,${PKGMANDIR}/,g'

.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../lang/python/distutils.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
