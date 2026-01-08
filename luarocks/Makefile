# $NetBSD$

DISTNAME=	luarocks-3.12.2
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=luarocks/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://luarocks.org/
COMMENT=	Package manager for Lua modules
LICENSE=	mit

USE_TOOLS+=	gmake
HAS_CONFIGURE=	yes

DEPENDS+=	unzip-[0-9]*:../../archivers/unzip

CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--rocks-tree=${PREFIX}/rocks
CONFIGURE_ARGS+=	--with-lua-bin=${LUA_INTERPRETER:H:Q}
CONFIGURE_ARGS+=	--with-lua-interpreter=${LUA_INTERPRETER:T:Q}

REQD_DIRS+=	${PKG_SYSCONFDIR}/luarocks
REQD_FILES+=	share/examples/luarocks/config-${LUA_VERSION_MAJOR}.${LUA_VERSION_MINOR}.lua \
		${PKG_SYSCONFDIR}/luarocks/config-${LUA_VERSION_MAJOR}.${LUA_VERSION_MINOR}.lua

INSTALLATION_DIRS+=	share/examples/luarocks
post-install:
	${MV} ${DESTDIR}${PKG_SYSCONFDIR}/luarocks/config-*.lua ${DESTDIR}${PREFIX}/share/examples/luarocks/

PRINT_PLIST_AWK+=	/\/config-${LUA_VERSION_MAJOR}\.${LUA_VERSION_MINOR}.lua$$/ \
			{ gsub(/${LUA_VERSION_MAJOR}\.${LUA_VERSION_MINOR}/, "$${LUA_VERSION_MAJOR}.$${LUA_VERSION_MINOR}") }
PLIST_SUBST+=		LUA_VERSION_MAJOR=${LUA_VERSION_MAJOR}
PLIST_SUBST+=		LUA_VERSION_MINOR=${LUA_VERSION_MINOR}

.include "../../lang/lua/module.mk"
.include "../../mk/bsd.pkg.mk"
