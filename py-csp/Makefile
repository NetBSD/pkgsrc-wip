# $NetBSD: Makefile,v 1.7 2010/05/08 19:41:02 jihbed Exp $
#

DISTNAME=	pycsp-0.7.0
EGG_NAME=	${DISTNAME}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	devel python
MASTER_SITES=	http://pycsp.googlecode.com/files/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://code.google.com/p/pycsp/
COMMENT=	PyCSP Python CSP Library
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-Pyro>=3.4:../../devel/py-Pyro
DEPENDS+=	${PYPKGPREFIX}-greenlet>=0.2:../../wip/py-greenlet
DEPENDS+=	${PYPKGPREFIX}-uuid>=1.30:../../wip/py-uuid

PKG_DESTDIR_SUPPORT=	user-destdir

PLIST_SUBST+=		PYVERSSUFFIX="-${PYVERSSUFFIX}"

EDGDIR=	${PREFIX}/share/examples/py-csp

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${EDGDIR}
	${INSTALL_DATA} ${WRKSRC}/test/*.py \
		${DESTDIR}${EDGDIR}

.include "../../devel/py-ctypes/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
