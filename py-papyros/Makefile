# $NetBSD: Makefile,v 1.5 2014/02/10 21:23:56 jihbed Exp $
#

DISTNAME=	papyros-0.2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	http://papyros.googlecode.com/files/
EXTRACT_SUFX=	.zip
LICENSE=	modified-bsd

MAINTAINER=	kamelderouiche@yahoo.com
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
