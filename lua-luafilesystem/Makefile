# $NetBSD$

DISTNAME=	luafilesystem-1.6.3
PKGNAME=	${LUA_PKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=keplerproject/}
GITHUB_TAG=	v${PKGVERSION_NOREV:C/\./_/g}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://keplerproject.github.io/luafilesystem/
COMMENT=	File system library to complement standard Lua distribution
LICENSE=	mit

USE_TOOLS+=	gmake
WRKSRC=		${WRKDIR}/luafilesystem-v_${PKGVERSION_NOREV:C/\./_/g}

SUBST_CLASSES+=		cfg
SUBST_MESSAGE.cfg=	Fixing paths
SUBST_STAGE.cfg=	pre-build
SUBST_FILES.cfg=	config
SUBST_VARS.cfg=		PREFIX
SUBST_VARS.cfg+=	LUA_CDIR
SUBST_VARS.cfg+=	LUA_INCDIR

do-build:
	cd ${WRKSRC} && ${GMAKE} src/lfs.so

.include "../../lang/lua/module.mk"

.include "../../mk/bsd.pkg.mk"
