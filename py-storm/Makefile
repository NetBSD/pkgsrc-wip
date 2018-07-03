# $NetBSD$

DISTNAME=	storm-0.20
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	https://launchpad.net/storm/trunk/0.20/+download/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://storm.canonical.com/
COMMENT=	Object-relational mapper (ORM) for Python
LICENSE=	gnu-lgpl-v2.1

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # as of 0.20

do-test:
	( cd ${WRKSRC} && ${PYTHONBIN} test )

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/py-storm
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/py-storm

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
