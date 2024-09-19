# $NetBSD$

DISTNAME=	panel-0.10.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/panel/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://panel.holoviz.org
COMMENT=	High level app and dashboarding solution for Python
LICENSE=	modified-bsd

PYTHON_VERSIONS_INCOMPATIBLE=	27

DEPENDS+=	${PYPKGPREFIX}-requests>=2.25.0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-bokeh>=2.2.2:../../wip/py-bokeh
DEPENDS+=	${PYPKGPREFIX}-ct>=0.4.8:../../wip/py-ct
DEPENDS+=	${PYPKGPREFIX}-markdown>=3.1.1:../../textproc/py-markdown
DEPENDS+=	${PYPKGPREFIX}-param>=1.10.0:../../wip/py-param
DEPENDS+=	${PYPKGPREFIX}-viz-comms>=0.7.6:../../wip/py-vis-comms
DEPENDS+=	${PYPKGPREFIX}-tornado>=5.1.1:../../www/py-tornado

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
