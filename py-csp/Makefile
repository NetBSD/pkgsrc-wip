# $NetBSD: Makefile,v 1.5 2009/10/20 10:11:14 jihbed Exp $
#

DISTNAME=	pycsp-0.6.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	devel python
MASTER_SITES=	http://pycsp.googlecode.com/files/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://code.google.com/p/pycsp/
COMMENT=	PyCSP Python CSP Library
#LICENSE=	LICENSE

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	${PYPKGPREFIX}-Pyro>=3.4:../../devel/py-Pyro
DEPENDS+=	${PYPKGPREFIX}-greenlet>=0.2:../../wip/py-greenlet

USE_LANGUAGES=	# none
PYTHON_VERSIONS_ACCEPTED= 26

PLIST_SUBST+=		PYVERSSUFFIX="-${PYVERSSUFFIX}"

EDGDIR=	${PREFIX}/share/examples/${PKGNAME}

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${EDGDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.py \
		${DESTDIR}${EDGDIR}

.include "../../devel/py-ctypes/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
