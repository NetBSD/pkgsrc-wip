# $NetBSD: Makefile,v 1.2 2009/05/19 22:11:43 jihbed Exp $
#

DISTNAME=	pycsp-0.6.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	devel python
MASTER_SITES=	http://pycsp.googlecode.com/files/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://code.google.com/p/pycsp/
COMMENT=	PyCSP Python CSP Library
#LICENSE=	LICENSE

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	${PYPKGPREFIX}-Pyro>=3.4:../../devel/py-Pyro

USE_LANGUAGES=	# none

PLIST_SUBST+=		PYVERSSUFFIX="-${PYVERSSUFFIX}"

EDGDIR=	${PREFIX}/share/examples/${PKGNAME}

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${EDGDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.py \
		${DESTDIR}${EDGDIR}

.include "../../devel/py-ctypes/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
