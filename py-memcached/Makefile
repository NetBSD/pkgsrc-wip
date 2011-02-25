# $NetBSD: Makefile,v 1.2 2011/02/25 09:47:48 thomasklausner Exp $
#

DISTNAME=	python-memcached-1.45
EGG_NAME=	${DISTNAME:S/python-//}
PKGNAME=	${PYPKGPREFIX}-${EGG_NAME}
CATEGORIES=	devel python
MASTER_SITES=	ftp://ftp.tummy.com/pub/python-memcached/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://www.tummy.com/Community/software/python-memcached/
COMMENT=	Python memcached client

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none

DOCDIR=	${PREFIX}/share/doc/py-memcached

PYTHON_VERSIONS_ACCEPTED= 27 26 25 24

INSTALLATION_DIRS=	${DOCDIR}

post-install:
	${INSTALL_DATA} ${WRKSRC}/memcache.html ${DESTDIR}${DOCDIR}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
