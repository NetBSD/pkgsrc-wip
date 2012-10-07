# $NetBSD: Makefile,v 1.7 2012/10/07 12:25:14 asau Exp $
#

DISTNAME=	py-1.0.2.tar
PKGNAME=	${PYPKGPREFIX}-lib-1.0.2
PKGREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	http://pypi.python.org/packages/source/p/py/
EXTRACT_SUFX=	.gz#md5=d64444015bac78e0c73ac285f9423750

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://pylib.org/
COMMENT=	Agile development and test support library
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-docutils>=0.5:../../textproc/py-docutils

WRKSRC=		${WRKDIR}/py-1.0.2
USE_LANGUAGES=	# none
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX:Q}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
