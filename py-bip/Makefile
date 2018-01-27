# $NetBSD: Makefile,v 1.8 2014/05/09 07:38:45 thomasklausner Exp $

DISTNAME=	BIP-0.5.4
EGG_NAME=	${DISTNAME}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/BIP/bip/}
PKGREVISION=	2
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=B/BIP/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://code.google.com/p/bayesian-inference/
COMMENT=	Python package for object-oriented bayesian inference
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-nose>=0.11.3:../../devel/py-nose
DEPENDS+=	${PYPKGPREFIX}-scipy>=0.7.0:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-liveplots>=0.7.1:../../wip/py-liveplots
DEPENDS+=	${PYPKGPREFIX}-openopt>=0.31:../../wip/py-openopt

USE_LANGUAGES=	# none

INSTALLATION_DIRS=		share/doc/py-bip/html
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 # py-multiprocess and py-gnuplot via py-liveplots

post-install:
	${INSTALL_DATA} ${WRKSRC}/html/* ${DESTDIR}${PREFIX}/share/doc/py-bip/html

.include "../../devel/py-cython/buildlink3.mk"
BUILDLINK_API_DEPENDS.pynumpy+=	${PYPKGPREFIX}-numpy>=1.0
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
