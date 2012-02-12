# $NetBSD: Makefile,v 1.5 2012/02/12 20:16:33 noud4 Exp $
#

DISTNAME=	BIP-0.5.4
EGG_NAME=	${DISTNAME}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/BIP/bip/}
PKGREVISION=	2
CATEGORIES=	math python
MASTER_SITES=	http://pypi.python.org/packages/source/B/BIP/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://code.google.com/p/bayesian-inference/
COMMENT=	Python package for object-oriented bayesian inference
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-nose>=0.11.3:../../devel/py-nose
DEPENDS+=	${PYPKGPREFIX}-scipy>=0.7.0:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-liveplots>=0.7.1:../../wip/py-liveplots
DEPENDS+=	${PYPKGPREFIX}-openopt>=0.31:../../wip/py-openopt

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none

INSTALLATION_DIRS=	share/doc/py-bip/html

post-install:
	${INSTALL_DATA} ${WRKSRC}/html/* ${DESTDIR}${PREFIX}/share/doc/py-bip/html

.include "../../devel/py-cython/buildlink3.mk"
BUILDLINK_API_DEPENDS.pynumpy+=	${PYPKGPREFIX}-numpy>=1.0
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
