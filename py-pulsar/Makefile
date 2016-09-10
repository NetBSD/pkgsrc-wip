# $NetBSD$

DISTNAME=	pulsar-1.4.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pulsar/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/quantmind/pulsar
COMMENT=	Event driven concurrent framework for Python
LICENSE=	2-clause-bsd

DEPENDS+=	${PYPKGPREFIX}-greenlet>=0.4.9:../../devel/py-greenlet
DEPENDS+=	${PYPKGPREFIX}-requests>=2.10.0:../../devel/py-requests

WRKSRC=	${WRKDIR}/pulsar-1.4.1

.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
