# $NetBSD: Makefile,v 1.1.1.1 2010/07/14 13:10:27 jihbed Exp $
#

DISTNAME=	AddOns-0.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/A/a/S/O/o/}
CATEGORIES=	devel
MASTER_SITES=	http://pypi.python.org/packages/source/A/AddOns/
EXTRACT_SUFX=	.zip

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://pypi.python.org/pypi/AddOns
COMMENT=	Dynamically extend other objects with AddOns

DEPENDS+=	${PYPKGPREFIX}-decoratortools>=1.8:../../wip/py-decoratortools

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none

DOCDIR=	${PREFIX}/share/doc/py-addons

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README.txt ${DESTDIR}${DOCDIR}


.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
