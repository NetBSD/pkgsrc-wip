# $NetBSD$

DISTNAME=	libqutrub-1.2.4.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_PYPI:=l/libqutrub/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://pypi.org/project/libqutrub
COMMENT=	Libqutrub Arabic verb conjuagtion library
LICENSE=	gnu-gpl-v3

post-extract:
	${MV} ${WRKSRC}/setup_lib.py ${WRKSRC}/setup.py

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
