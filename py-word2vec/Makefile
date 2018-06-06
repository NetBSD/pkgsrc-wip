# $NetBSD$

DISTNAME=	word2vec-0.9.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=w/word2vec/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/danielfrg/word2vec
COMMENT=	Python interface to Google word2vec
LICENSE=	apache-2.0

.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
