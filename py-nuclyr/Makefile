# $NetBSD$

DISTNAME=	nuclyr-0.17
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	python # TODO: add primary category
MASTER_SITES=	${MASTER_SITE_PYPI:=n/nuclyr/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/phScholz/nuclyr
COMMENT=	Utility package for nuclear physics data
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-selenium>=0:../../www/py-selenium
DEPENDS+=	${PYPKGPREFIX}-pandas>=0:../../math/py-pandas
DEPENDS+=	${PYPKGPREFIX}-requests>=0:../../devel/py-requests

USE_LANGUAGES=	# none

post-extract:
	${CHMOD} -R go-w ${WRKSRC}

BUILDLINK_API_DEPENDS.py-numpy+=	${PYPKGPREFIX}-numpy>=1.0
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
