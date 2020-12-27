# $NetBSD$

DISTNAME=	pixiedust-1.1.18
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pixiedust/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/pixiedust/pixiedust
COMMENT=	Productivity library for Jupyter Notebook
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-ipykernel>=5.3.4:../../devel/py-ipykernel
DEPENDS+=	${PYPKGPREFIX}-jupyter_client>=6.1.7:../../devel/py-jupyter_client
DEPENDS+=	${PYPKGPREFIX}-nbformat>=5.0.8:../../www/py-nbformat
DEPENDS+=	${PYPKGPREFIX}-requests>=2.25.0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-traitlets>=4.3.3:../../devel/py-traitlets
DEPENDS+=	${PYPKGPREFIX}-geojson>=2.5.0:../../geography/py-geojson
DEPENDS+=	${PYPKGPREFIX}-markdown>=3.1.1:../../textproc/py-markdown
DEPENDS+=	${PYPKGPREFIX}-colour>=0.1.5:../../textproc/py-colour
DEPENDS+=	${PYPKGPREFIX}-lxml>=4.6.2:../../textproc/py-lxml
DEPENDS+=	${PYPKGPREFIX}-astunparse>=1.6.3:../../wip/py-astunparse
DEPENDS+=	${PYPKGPREFIX}-mpld3>=0.5.2:../../category/py-mpld3

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
