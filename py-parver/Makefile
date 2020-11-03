# $NetBSD$

DISTNAME=	parver-0.3.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/parver/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/RazerM/parver
COMMENT=	Parse and manipulate version numbers
LICENSE=	mit

#DEPENDS+=	${PYPKGPREFIX}-arpeggio>=1.10.1:../../wip/py-arpeggio
DEPENDS+=	${PYPKGPREFIX}-attrs>=19.3.0:../../devel/py-attrs
DEPENDS+=	${PYPKGPREFIX}-six>=1.15.0:../../lang/py-six

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
