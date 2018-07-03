# $NetBSD: Makefile,v 1.2 2012/10/06 17:13:27 asau Exp $
#

DISTNAME=	AddOns-0.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/A/a/S/O/o/}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=A/AddOns/}
EXTRACT_SUFX=	.zip
LICENSE=	python-software-foundation # or ZPL

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://pypi.python.org/pypi/AddOns
COMMENT=	Dynamically extend other objects with AddOns

DEPENDS+=	${PYPKGPREFIX}-decoratortools>=1.8:../../wip/py-decoratortools

USE_LANGUAGES=	# none
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # py-decoratortools

DOCDIR=	${PREFIX}/share/doc/py-addons

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README.txt ${DESTDIR}${DOCDIR}


.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
