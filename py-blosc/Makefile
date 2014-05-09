# $NetBSD: Makefile,v 1.1 2014/05/09 23:00:49 jihbed Exp $

DISTNAME=	blosc-1.2.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	https://pypi.python.org/packages/source/b/blosc/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://github.com/blosc/python-blosc
COMMENT=	Blosc is a high performance compressor optimized for binary data
LICENSE=	mit

USE_LANGUAGES=	c c++

PYTHON_VERSIONS_ACCEPTED= 31 27 26
PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
