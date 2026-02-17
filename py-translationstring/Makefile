# $NetBSD$

DISTNAME=	translationstring-1.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=t/translationstring/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/Pylons/translationstring
COMMENT=	Library for i18n relied on by various Repoze and Pyramid
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel

WRKSRC=			${WRKDIR}/${DISTNAME}

USE_LANGUAGES=		# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
