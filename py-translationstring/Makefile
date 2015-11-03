# $NetBSD$

DISTNAME=	translationstring-1.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	https://pypi.python.org/packages/source/t/translationstring/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://pylonsproject.org
COMMENT= 	Library for i18n relied on by various Repoze and Pyramid
LICENSE=	modified-bsd

WRKSRC=			${WRKDIR}/translationstring-1.3

USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		# none

PYTHON_VERSIONS_ACCEPTED= 34 33 27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
