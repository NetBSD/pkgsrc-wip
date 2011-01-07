# $NetBSD: Makefile,v 1.1.1.1 2011/01/07 07:23:51 rubengonzalez Exp $
#

DISTNAME=	arandr-0.1.4
CATEGORIES=	x11
MASTER_SITES=	http://christian.amsuess.com/tools/arandr/files/

MAINTAINER=	rga@sdf.lonestar.org
HOMEPAGE=	http://christian.amsuess.com/tools/arandr/
COMMENT=	Designed to provide a simple visual front end for XRandR 1.2/1.3
LICENSE=	gnu-gpl-v3

DEPENDS+=       ${PYPKGPREFIX}-docutils>=0.6:../../textproc/py-docutils
DEPENDS+=	xrandr>=1.2:../../x11/xrandr

PKG_DESTDIR_SUPPORT=	user-destdir

PYSETUP = setup.py

NO_BUILD= YES

# Adjust setup.py
SUBST_CLASSES+=         setup
SUBST_STAGE.setup=      pre-configure
SUBST_MESSAGE.setup=    Fixing ${PYSETUP}
SUBST_FILES.setup=      ${PYSETUP}
SUBST_SED.setup+=       -e 's,share/man/,${PKGMANDIR}/,g'

do-install:
	cd ${WRKSRC}; \
	${PYTHONBIN} ${PYSETUP}	install

.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
