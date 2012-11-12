# $NetBSD: Makefile,v 1.3 2012/11/12 16:26:51 othyro Exp $
#

DISTNAME=	SimpleParse-2.1.1a2
PKGNAME=	${PYPKGPREFIX}-simpleparse-mxtexttools-2.1.1
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=simpleparse/}

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
