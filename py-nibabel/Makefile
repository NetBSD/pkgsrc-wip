# $NetBSD: Makefile,v 1.3 2012/10/07 12:25:26 asau Exp $
#

DISTNAME=	nibabel-1.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	science python
MASTER_SITES=	http://pypi.python.org/packages/source/n/nibabel/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://nipy.org/nibabel
COMMENT=	Access a multitude of neuroimaging data formats
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-nose>=0.11.3:../../devel/py-nose
DEPENDS+=	${PYPKGPREFIX}-rpy>=2.1.3:../../math/py-rpy
DEPENDS+=	${PYPKGPREFIX}-sphinx>=1.0.7:../../textproc/py-sphinx

WRKSRC=		${WRKDIR}/nibabel-1.1.0

USE_LANGUAGES=	# none

PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
