# $NetBSD$

DISTNAME=	joblib-0.9.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
PKGREVISION=	2
MASTER_SITES=	${MASTER_SITE_PYPI:=j/joblib/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://packages.python.org/joblib/
COMMENT=	Lightweight pipelining: using Python functions as pipeline jobs
LICENSE=	modified-bsd

BUILD_DEPENDS+=	${PYPKGPREFIX}-nose>=1.3.7:../../devel/py-nose

WRKSRC=		${WRKDIR}/joblib-0.9.3
USE_LANGUAGES=	# none

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
