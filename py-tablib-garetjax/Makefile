# $NetBSD: Makefile,v 1.1 2013/09/20 10:45:21 jihbed Exp $

DISTNAME=	tablib-garetjax-0.9.12
EGG_NAME=       tablib_garetjax
PKGNAME=        ${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc
MASTER_SITES=	https://pypi.python.org/packages/source/t/tablib-garetjax/
FETCH_USING=	curl

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://python-tablib.org/
COMMENT=	Format agnostic tabular data library (XLS, JSON, YAML, CSV)
LICENSE=	mit

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
DEPENDS+=    	${PYPKGPREFIX}-yaml>=3.10:../../textproc/py-yaml
.include "../../mk/bsd.pkg.mk"
