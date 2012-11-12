# $NetBSD: Makefile,v 1.6 2012/11/12 16:51:37 othyro Exp $
#

DISTNAME=	PyPedal-2.0.0rc7
PKGNAME=	${PYPKGPREFIX}-pypedal-2.0.0
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pypedal/}
EXTRACT_SUFX=	.zip

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://pypedal.sourceforge.net/
COMMENT=	Tools for pedigree analysis
LICENSE=	gnu-lgpl-v2

DEPENDS+=	${PYPKGPREFIX}-networkx>=1.0.1:../../math/py-networkx
DEPENDS+=	${PYPKGPREFIX}-pydot>=1.0.2:../../wip/py-pydot

USE_LANGUAGES=	# none

DOCDIR=	${PREFIX}/share/doc/py-pedal

INSTALLATION_DIRS=	${DOCDIR}

post-install:
	${INSTALL_DATA} ${WRKSRC}/PyPedal/doc/pypedal.pdf	${DESTDIR}${DOCDIR}

.include "../../lang/python/egg.mk"
.include "../../graphics/py-matplotlib/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../time/py-mxDateTime/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
