# $NetBSD: Makefile,v 1.1.1.1 2010/05/07 11:01:14 jihbed Exp $
#

DISTNAME=	PyPedal-2.0.0rc7
PKGNAME=	${PYPKGPREFIX}-pypedal-2.0.0
CATEGORIES=	math python
MASTER_SITES=	http://switch.dl.sourceforge.net/project/pypedal/pypedal-2.0.0/2.0.0rc7/
EXTRACT_SUFX=	.zip

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://pypedal.sourceforge.net/
COMMENT=	Tools for pedigree analysis
LICENSE=	gnu-lgpl-v2

DEPENDS+=	${PYPKGPREFIX}-psyco-[0-9]*:../../lang/py-psyco
DEPENDS+=	${PYPKGPREFIX}-networkx>=1.0.1:../../math/py-networkx
DEPENDS+=	${PYPKGPREFIX}-pydot>=1.0.2:../../wip/py-pydot

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none

PYTHON_VERSIONS_ACCEPTED= 26 25 24

DOCDIR=	${PREFIX}/share/doc/py-pedal

INSTALLATION_DIRS=	${DOCDIR}

post-install:
	${INSTALL_DATA} ${WRKSRC}/PyPedal/doc/pypedal.pdf	${DESTDIR}${DOCDIR}

.include "../../lang/python/egg.mk"
.include "../../graphics/py-matplotlib/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../time/py-mxDateTime/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
