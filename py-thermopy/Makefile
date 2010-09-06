# $NetBSD: Makefile,v 1.1.1.1 2010/09/06 13:53:43 jihbed Exp $
#

DISTNAME=	thermopy-0.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	biology python
MASTER_SITES=	http://pypi.python.org/packages/source/t/thermopy/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://packages.python.org/thermopy
COMMENT=	Some utilities for Thermodynamics and Thermochemistry
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-scipy>=0.7.0:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-cElementTree-[0-9]*:../../textproc/py-cElementTree

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/thermopy-0.3
USE_LANGUAGES=	# none

PYTHON_VERSIONS_ACCEPTED= 26 25

.include "../../lang/python/egg.mk"
BUILDLINK_API_DEPENDS.pynumpy+=	${PYPKGPREFIX}-numpy>=1.0
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
