# $NetBSD: Makefile,v 1.2 2014/12/31 13:58:34 thomasklausner Exp $

DISTNAME=	python-modargs-1.7
PKGNAME=	${PYPKGPREFIX}-modargs-1.7
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-modargs/}

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://pypi.python.org/pypi/python-modargs
COMMENT=	line argument parsing library that infers

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # not yet ported as of 1.7
USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
