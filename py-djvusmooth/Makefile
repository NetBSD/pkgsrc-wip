# $NetBSD: Makefile,v 1.8 2012/04/08 19:09:46 thomasklausner Exp $
#

DISTNAME=	djvusmooth-0.2.10
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	graphics textproc
MASTER_SITES=	http://pypi.python.org/packages/source/d/djvusmooth/

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://jwilk.net/software/djvusmooth
COMMENT=	Graphical editor for DjVu documents
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

INSTALLATION_DIRS=	${PKGMANDIR}/man1

USE_LANGUAGES=	# none

DEPENDS+=	${PYPKGPREFIX}-xdg:../../devel/py-xdg
DEPENDS+=	${PYPKGPREFIX}-wxWidgets:../../x11/py-wxWidgets
DEPENDS+=	${PYPKGPREFIX}-djvulibre:../../wip/py-djvulibre
DEPENDS+=	djvulibre-tools:../../graphics/djvulibre-tools

PYDISTUTILSPKG=	yes

SUBST_CLASSES+=		fix-paths
SUBST_STAGE.fix-paths=	pre-configure
SUBST_FILES.fix-paths=	setup.py
SUBST_SED.fix-paths=	-e 's,share/man,${PKGMANDIR},'

.include "../../lang/python/extension.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
