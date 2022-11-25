# $NetBSD$

DISTNAME=	spyder-notebook-0.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/spyder-notebook/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/spyder-ide/spyder-notebook
COMMENT=	Jupyter notebook integration with Spyder
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-nbformat-[0-9]*:../../www/py-nbformat
DEPENDS+=	${PYPKGPREFIX}-jupyter_core>=4.10.0:../../devel/py-jupyter_core
DEPENDS+=	${PYPKGPREFIX}-traitlets-[0-9]*:../../devel/py-traitlets
DEPENDS+=	${PYPKGPREFIX}-notebook>=4.3:../../www/py-notebook
DEPENDS+=	${PYPKGPREFIX}-QtPy-[0-9]*:../../wip/py-qtpy
DEPENDS+=	${PYPKGPREFIX}-jinja2-[0-9]*:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-qdarkstyle>=3.0.2:../../wip/py-qdarkstyle
DEPENDS+=	spyder>=5.4.0:../../wip/spyder

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
