# $NetBSD: Makefile,v 1.2 2014/06/01 12:49:47 thomasklausner Exp $

DISTNAME=	tablib-garetjax-0.9.12
EGG_NAME=       tablib_garetjax
PKGNAME=        ${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc
MASTER_SITES=	https://pypi.python.org/packages/source/t/tablib-garetjax/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://python-tablib.org/
COMMENT=	Format agnostic tabular data library (XLS, JSON, YAML, CSV)
LICENSE=	mit

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
DEPENDS+=    	${PYPKGPREFIX}-yaml>=3.10:../../textproc/py-yaml
.include "../../mk/bsd.pkg.mk"
