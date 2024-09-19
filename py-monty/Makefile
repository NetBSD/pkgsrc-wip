# $NetBSD$

DISTNAME=	monty-0.7.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=m/monty/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/materialsvirtuallab/monty
COMMENT=	Monty is the missing complement to Python
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-six>=1.10.0:../../lang/py-six

WRKSRC=		${WRKDIR}/monty-0.7.2

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
