# $NetBSD: Makefile,v 1.1.1.1 2011/03/20 22:51:12 jihbed Exp $
#

DISTNAME=	dana-0.3.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	http://pypi.python.org/packages/source/d/dana/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://dana.loria.fr/
COMMENT= Framework for distributed, asynchronous and adaptive computing
LICENSE=	modified-bsd

#DEPENDS+=	${PYPKGPREFIX}-scipy>=0.7.0:../../math/py-scipy

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/dana-0.3.1

USE_LANGUAGES=	# none
PYDISTUTILSPKG=	yes

do-test:
	${RUN} cd ${WRKSRC}; ${SETENV} ${TEST_ENV} ${PYTHONBIN} dana/tests/__init__.py

.include "../../graphics/py-matplotlib/buildlink3.mk"
.include "../../lang/python/extension.mk"
BUILDLINK_API_DEPENDS.pynumpy+=	${PYPKGPREFIX}-numpy>=1.0
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
