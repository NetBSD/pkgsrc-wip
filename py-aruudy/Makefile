# $NetBSD$

DISTNAME=	aruudy-0.5.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/aruudy/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/kariminf/aruudy
COMMENT=	Arabic poetry package
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-Levenshtein>=0.12.2:../../textproc/py-Levenshtein
DEPENDS+=	${PYPKGPREFIX}-lang-trans>=0.6.0:../../wip/py-lang-trans

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
