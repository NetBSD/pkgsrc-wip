# $NetBSD$

DISTNAME=	randomdict-0.2.0
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=r/randomdict/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/robtandy/randomdict
COMMENT=	Python dictionaries with O(1) random element access
#LICENSE=	# TODO: (see mk/license.mk)

DEPENDS+=	${PYPKGPREFIX}-nose>=1.3.7:../../devel/py-nose

.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
