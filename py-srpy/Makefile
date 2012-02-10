# $NetBSD: Makefile,v 1.4 2012/02/10 09:01:10 noud4 Exp $
#

DISTNAME=	srpy-0.2.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	http://srpy.googlecode.com/files/
EXTRACT_SUFX=	.zip

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://code.google.com/p/srpy/
COMMENT=	Easy access and remote control of local/remote Python instances
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-Pyro>=-3.4:../../devel/py-Pyro

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	pax
USE_LANGUAGES=	# none

PYTHON_VERSIONS_ACCEPTED= 27 26 25

HTMLDIR=	${PREFIX}/share/doc/html/py-srpy

INSTALLATION_DIRS+=	share/doc/py-srpy ${HTMLDIR}

PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX:Q}

post-install:
	${INSTALL_DATA} ${WRKSRC}/README.txt \
		 ${DESTDIR}${PREFIX}/share/doc/py-srpy
	${INSTALL_DATA} ${WRKSRC}/"SRPy 0.2.3 Manual.pdf" \
		${DESTDIR}${PREFIX}/share/doc/py-srpy
	${INSTALL_DATA_DIR} ${DESTDIR}${HTMLDIR}
	cd ${WRKSRC}/doc && pax -rw -pp * ${DESTDIR}${HTMLDIR}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
