# $NetBSD: Makefile,v 1.2 2015/04/13 23:22:02 othyro Exp $

DISTNAME=	blosc-1.2.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	https://pypi.python.org/packages/source/b/blosc/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://github.com/blosc/python-blosc
COMMENT=	Blosc is a high performance compressor optimized for binary data
LICENSE=	mit

USE_LANGUAGES=	c c++

PYTHON_VERSIONS_ACCEPTED= 27
PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
