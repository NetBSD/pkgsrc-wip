# $NetBSD: Makefile,v 1.2 2012/10/07 13:57:30 asau Exp $
#

DISTNAME=	SimpleParse-2.1.1a2
PKGNAME=	${PYPKGPREFIX}-simpleparse-mxtexttools-2.1.1
CATEGORIES=	textproc python
MASTER_SITES=	http://garr.dl.sourceforge.net/project/simpleparse/simpleparse/2.1.1a2/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://simpleparse.sourceforge.net/
COMMENT=	SimpleParse is a Python providing a simple and fast parser generator
#LICENSE=	# TODO: (see mk/license.mk)

INSTALLATION_DIRS+= 	share/doc/py-simpleparse-mxtexttools

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/py-simpleparse-mxtexttools
	${INSTALL_DATA} ${WRKSRC}/doc/* \
		 ${DESTDIR}${PREFIX}/share/doc/py-simpleparse-mxtexttools

.include "../../lang/python/egg.mk"
.include "../../time/py-mxDateTime/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
