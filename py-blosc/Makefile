# $NetBSD: Makefile,v 1.3 2015/04/14 11:56:20 thomasklausner Exp $

DISTNAME=	blosc-1.2.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/blosc/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://github.com/blosc/python-blosc
COMMENT=	Blosc is a high performance compressor optimized for binary data
LICENSE=	mit

USE_LANGUAGES=	c c++

PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
