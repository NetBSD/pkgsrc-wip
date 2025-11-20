# $NetBSD$

DISTNAME=	lmdbxx-1.0.0
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_GITHUB:=hoytech/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/hoytech/lmdbxx/
COMMENT=	C++ wrapper for the LMDB embedded database library
LICENSE=	unlicense

USE_LANGUAGES=		# none
NO_BUILD=		yes
INSTALLATION_DIRS=	include

do-install:
	${INSTALL_DATA} ${WRKSRC}/lmdb++.h ${DESTDIR}${PREFIX}/include/

.include "../../mk/bsd.pkg.mk"
