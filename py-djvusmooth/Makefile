# $NetBSD: Makefile,v 1.14 2014/05/09 07:38:46 thomasklausner Exp $

DISTNAME=	djvusmooth-0.2.10
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	graphics textproc
MASTER_SITES=	${MASTER_SITE_PYPI:=d/djvusmooth/}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://jwilk.net/software/djvusmooth
COMMENT=	Graphical editor for DjVu documents
LICENSE=	gnu-gpl-v2

INSTALLATION_DIRS=	${PKGMANDIR}/man1

USE_LANGUAGES=	# none

DEPENDS+=	${PYPKGPREFIX}-xdg-[0-9]*:../../devel/py-xdg
DEPENDS+=	${PYPKGPREFIX}-wxWidgets-[0-9]*:../../x11/py-wxWidgets
DEPENDS+=	${PYPKGPREFIX}-djvulibre-[0-9]*:../../wip/py-djvulibre
DEPENDS+=	djvulibre-tools-[0-9]*:../../graphics/djvulibre-tools

PYDISTUTILSPKG=	yes
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # py-wxWidgets

SUBST_CLASSES+=		fix-paths
SUBST_STAGE.fix-paths=	pre-configure
SUBST_FILES.fix-paths=	setup.py
SUBST_SED.fix-paths=	-e 's,share/man,${PKGMANDIR},'

.include "../../lang/python/extension.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
