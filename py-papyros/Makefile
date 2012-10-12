# $NetBSD: Makefile,v 1.4 2012/10/12 11:46:59 asau Exp $
#

DISTNAME=	papyros-0.2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	http://papyros.googlecode.com/files/
EXTRACT_SUFX=	.zip

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://code.google.com/p/papyros/
COMMENT=	Pythonic parallel processing

DEPENDS+=	${PYPKGPREFIX}-Pyro4>=3.4:../../devel/py-Pyro

USE_LANGUAGES=	# none
PYDISTUTILSPKG=	yes

DOCDIR=	${PREFIX}/share/doc/${PKGNAME}

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/* \
		${DESTDIR}${DOCDIR}

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
