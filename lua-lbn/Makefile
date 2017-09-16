# $NetBSD: Makefile,v 1.3 2013/03/19 05:01:44 alnsn Exp $
#

DISTNAME=	lbn
PKGNAME=	lua-lbn-${LBN_VERSION}
CATEGORIES=	math
MASTER_SITES=	http://www.tecgraf.puc-rio.br/~lhf/ftp/lua/${LVER}/

MAINTAINER=	alnsn@yandex.ru
HOMEPAGE=	http://www.tecgraf.puc-rio.br/~lhf/ftp/lua/#lbn
COMMENT=	Arbitrary precision library for Lua based on OpenSSL bn
LICENSE=	public-domain

# There are two distfiles for different versions of Lua and
# both distfiles are named lbn.tar.gz. Fetch the file to
# lbn-5.x directory and make up the version.
LVER=		${LUA_VERSION_MAJOR}.${LUA_VERSION_MINOR}
LBN_VERSION=	20130319
DIST_SUBDIR=	lbn-${LVER}

NO_CONFIGURE=	yes
BUILD_TARGET=	bn.so
TEST_TARGET=	test

WRKSRC=			${WRKDIR}/bn
MAKEFLAGS+=		G=-fPIC
LBN_README_DIR=		 share/doc/${PKGBASE}
INSTALLATION_DIRS+=	${LUA_CDIR} ${LBN_README_DIR}

.include "../../lang/lua/module.mk"

do-install:
	${INSTALL_LIB} ${WRKSRC}/bn.so \
	                ${DESTDIR}${PREFIX}/${LUA_CDIR}
	${INSTALL_DATA} ${WRKSRC}/README \
	                ${DESTDIR}${PREFIX}/${LBN_README_DIR}

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
