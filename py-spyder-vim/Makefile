# $NetBSD$

DISTNAME=	spyder-vim-0.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/spyder-vim/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/spyder-ide/spyder-vim
COMMENT=	Plugin to enable vim keybindings to the spyder editor
LICENSE=	mit

PYTHON_VERSIONS_INCOMPATIBLE=	27

DEPENDS+=	${PYPKGPREFIX}-QtPy-[0-9]*:../../wip/py-qtpy
DEPENDS+=	${PYPKGPREFIX}-qtawesome>=1.2.1:../../wip/py-qtawesome
DEPENDS+=	spyder>=5.4.0:../../wip/spyder

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
