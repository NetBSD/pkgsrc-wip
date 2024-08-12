# $NetBSD$

DISTNAME=	rfc6555-0.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	https://files.pythonhosted.org/packages/f6/4b/24f953c3682c134e4d0f83c7be5ede44c6c653f7d2c0b06ebb3b117f005a/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.github.com/sethmlarson/rfc6555
COMMENT=	Implementation of the Happy Eyeballs Algorithm described in RFC 6555
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-selectors2>=2.0.1:../../devel/py-selectors2

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
