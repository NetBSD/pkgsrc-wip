# $NetBSD: Makefile,v 1.2 2010/05/07 22:41:52 jihbed Exp $
#

DISTNAME=	storm-0.16.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	http://launchpad.net/storm/trunk/0.16/+download/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://storm.canonical.com/
COMMENT=	Object-relational mapper (ORM) for Python
LICENSE=	gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

do-test:
	( cd ${WRKSRC} && ${PYTHONBIN} test )

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/py-storm
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/py-storm

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
