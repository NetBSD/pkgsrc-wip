# $NetBSD: Makefile,v 1.8 2012/10/12 11:47:00 asau Exp $

DISTNAME=	srpy-0.2.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
EGG_NAME=	${DISTNAME:S|srp|SRP|:Q}
PKGREVISION=	3
CATEGORIES=	devel python
MASTER_SITES=	http://srpy.googlecode.com/files/
EXTRACT_SUFX=	.zip

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://code.google.com/p/srpy/
COMMENT=	Easy access and remote control of local/remote Python instances
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-Pyro4>=-3.4:../../devel/py-Pyro

USE_TOOLS+=	pax
USE_LANGUAGES=	# none
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # as of 0.2.3

HTMLDIR=	${PREFIX}/share/doc/html/py-srpy

INSTALLATION_DIRS+=	share/doc/py-srpy ${HTMLDIR}

post-install:
	${INSTALL_DATA} ${WRKSRC}/README.txt \
		 ${DESTDIR}${PREFIX}/share/doc/py-srpy
	${INSTALL_DATA} ${WRKSRC}/"SRPy 0.2.3 Manual.pdf" \
		${DESTDIR}${PREFIX}/share/doc/py-srpy
	${INSTALL_DATA_DIR} ${DESTDIR}${HTMLDIR}
	cd ${WRKSRC}/doc && pax -rw -pp * ${DESTDIR}${HTMLDIR}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
