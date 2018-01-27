# $NetBSD: Makefile,v 1.2 2015/08/09 23:53:18 jihbed Exp $

DISTNAME=	ordereddict-1.1
 PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=o/ordereddict/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://pypi.python.org/pypi/ordereddict/
COMMENT=	Drop-in substitute for Py2.7's new collections
LICENSE=	mit

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
