# $NetBSD: Makefile,v 1.11 2014/05/09 07:38:49 thomasklausner Exp $

DISTNAME=	PyPedal-2.0.0rc7
PKGNAME=	${PYPKGPREFIX}-pypedal-2.0.0
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pypedal/}
EXTRACT_SUFX=	.zip

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://pypedal.sourceforge.net/
COMMENT=	Tools for pedigree analysis
LICENSE=	gnu-lgpl-v2

DEPENDS+=	${PYPKGPREFIX}-dot>=1.0.2:../../graphics/py-dot
DEPENDS+=	${PYPKGPREFIX}-matplotlib-[0-9]*:../../graphics/py-matplotlib
DEPENDS+=	${PYPKGPREFIX}-networkx>=1.0.1:../../math/py-networkx

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # py-mxDateTime

USE_LANGUAGES=	# none

DOCDIR=	${PREFIX}/share/doc/py-pedal

INSTALLATION_DIRS=	${DOCDIR}

post-install:
	${INSTALL_DATA} ${WRKSRC}/PyPedal/doc/pypedal.pdf	${DESTDIR}${DOCDIR}

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../time/py-mxDateTime/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
