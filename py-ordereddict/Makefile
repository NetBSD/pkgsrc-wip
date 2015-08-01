# $NetBSD: Makefile,v 1.1 2015/08/01 23:04:57 jihbed Exp $

DISTNAME=	ordereddict-1.1
 PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	https://pypi.python.org/packages/source/o/ordereddict/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://pypi.python.org/pypi/ordereddict/
COMMENT=	A drop-in substitute for Py2.7's new collections
LICENSE=	mit

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE= 33 34

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
