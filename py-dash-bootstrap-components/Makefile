# $NetBSD$

DISTNAME=	dash-bootstrap-components-0.10.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/swh.scanner/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://dash-bootstrap-components.opensource.faculty.ai
COMMENT=	Bootstrap themed components for use in Plotly Dash
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-dash>=1.9.0:../../devel/py-dash

USE_LANGUAGES=	# none

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
