# $NetBSD$

DISTNAME=	${GITHUB_PROJECT}-${PKGVERSION_NOREV}
PKGNAME=	${LUA_PKGPREFIX}-${GITHUB_PROJECT}-1.2.6
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_GITHUB:=lualdap/}
GITHUB_PROJECT=	lualdap
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/lualdap/lualdap/
COMMENT=	Binding for the OpenLDAP client libraries
LICENSE=	modified-bsd

USE_LANGUAGES=	c
USE_TOOLS=	gmake

BUILD_TARGET=	src/lualdap.so
MAKE_FLAGS+=	LUA=${LUA_INTERPRETER:Q}
MAKE_FLAGS+=	LUA_INCDIR=${PREFIX}/${LUA_INCDIR:Q}
MAKE_FLAGS+=	LUA_LIB=-llua${LUA_VERSION_MAJOR}.${LUA_VERSION_MINOR}
MAKE_FLAGS+=	LUA_LIBDIR=${PREFIX:Q}/lib
MAKE_FLAGS+=	LBER_INCDIR=${PREFIX:Q}/include
MAKE_FLAGS+=	LBER_LIBDIR=${PREFIX:Q}/lib
MAKE_FLAGS+=	LDAP_INCDIR=${PREFIX:Q}/include
MAKE_FLAGS+=	LDAP_LIBDIR=${PREFIX:Q}/lib
MAKE_FLAGS+=	INST_BINDIR=${PREFIX:Q}/bin
MAKE_FLAGS+=	INST_LIBDIR=${PREFIX:Q}/${LUA_CDIR:Q}
#XXX apparently required on macOS
MAKE_FLAGS+=	LIBFLAG=

.include "../../databases/openldap-client/buildlink3.mk"
.include "../../lang/lua/module.mk"
.include "../../mk/bsd.pkg.mk"
