# $NetBSD: Makefile,v 1.3 2014/12/31 13:58:44 thomasklausner Exp $

DISTNAME=	tablib-garetjax-0.9.12
PKGNAME=        ${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc
MASTER_SITES=	https://pypi.python.org/packages/source/t/tablib-garetjax/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://python-tablib.org/
COMMENT=	Format agnostic tabular data library (XLS, JSON, YAML, CSV)
LICENSE=	mit

DEPENDS+=    	${PYPKGPREFIX}-yaml>=3.10:../../textproc/py-yaml

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 35 # not yet ported as of 0.9.12
USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
