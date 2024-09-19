# $NetBSD$

DISTNAME=	mozcrash-2.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel www python
MASTER_SITES=	https://files.pythonhosted.org/packages/39/54/fd9281d9337cc9c5c17e96bdc97bc033ec8048430153f0f881ce0be2d244/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://wiki.mozilla.org/Auto-tools/Projects/Mozbase
COMMENT=	Library for printing stack traces from minidumps
LICENSE=	mpl-2.0

DEPENDS+=	# ${PYPKGPREFIX}-mozfile>=1.0
DEPENDS+=	# ${PYPKGPREFIX}-mozlog>=6.0

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
