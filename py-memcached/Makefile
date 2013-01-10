# $NetBSD: Makefile,v 1.5 2013/01/10 17:52:06 othyro Exp $
#

DISTNAME=	python-memcached-1.48
EGG_NAME=	${DISTNAME:S/python-//}
PKGNAME=	${PYPKGPREFIX}-${EGG_NAME}
CATEGORIES=	devel python
MASTER_SITES=	ftp://ftp.tummy.com/pub/python-memcached/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://www.tummy.com/Community/software/python-memcached/
COMMENT=	Python memcached client
LICENSE=	python-software-foundation

USE_LANGUAGES=	# none

DOCDIR=		${PREFIX}/share/doc/py-memcached

INSTALLATION_DIRS=	${DOCDIR}
REPLACE_PYTHON+=	memcache.py

post-install:
	${INSTALL_DATA} ${WRKSRC}/memcache.html ${DESTDIR}${DOCDIR}

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
