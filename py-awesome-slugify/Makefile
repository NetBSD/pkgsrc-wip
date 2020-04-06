# $NetBSD$

DISTNAME=	awesome-slugify-1.6.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/awesome-slugify/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/dimka665/awesome-slugify
COMMENT=	Python flexible slugify function
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	# none

DEPENDS+=	${PYPKGPREFIX}-Unidecode>=0.04.14:../../textproc/py-Unidecode

.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
