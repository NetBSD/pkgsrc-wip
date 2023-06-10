# $NetBSD$

DISTNAME=	digestif-0.5.1
PKGNAME=	${LUA_PKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc lua
MASTER_SITES=	${MASTER_SITE_GITHUB:=astoff/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/astoff/digestif/
COMMENT=	Language server for TeX and friends
#LICENSE=	# TODO: (see mk/license.mk)

TOOL_DEPENDS+=	${LUA_PKGPREFIX}-rocks-[0-9]*:../../devel/lua-rocks
TOOL_DEPENDS+=	git-base-[0-9]*:../../devel/git-base
DEPENDS+=	${LUA_PKGPREFIX}-cjson-[0-9]*:../../textproc/lua-cjson
DEPENDS+=	${LUA_PKGPREFIX}-filesystem-[0-9]*:../../devel/lua-filesystem
DEPENDS+=	${LUA_PKGPREFIX}-lpeg-[0-9]*:../../devel/lua-lpeg

USE_LANGUAGES=			# none
WRKSRC=				${WRKDIR}/${DISTNAME}
REPLACE_LUA+=			bin/*
REPLACE_LUA+=			scripts/*
LUA_VERSIONS_INCOMPATIBLE=	51 52

SUBST_CLASSES+=		version
SUBST_SED.version+=	-e "s,dev-1,${PKGVERSION_NOREV}-1,"
SUBST_FILES.version+=	digestif-${PKGVERSION_NOREV}-1.rockspec
SUBST_STAGE.version=	pre-build
SUBST_MESSAGE.version=	Fixing version number.

SUBST_CLASSES+=		path
SUBST_SED.path+=	-e "s,${DESTDIR},,g"
SUBST_SED.path+=	-e "s,/usr/bin/env lua,${LUA_INTERPRETER},g"
SUBST_FILES.path+=	${DESTDIR}${PREFIX}/bin/digestif
SUBST_FILES.path+=	${DESTDIR}${PREFIX}/lib/luarocks/rocks-${_LUA_DOT_VERSION}/digestif/${PKGVERSION_NOREV}-1/bin/digestif
SUBST_STAGE.path=	post-install
SUBST_MESSAGE.path=	Fix path to binary.

post-extract:
	cd ${WRKSRC} && ${MV} digestif-dev-1.rockspec digestif-${PKGVERSION_NOREV}-1.rockspec

do-build:

do-install:
	cd ${WRKSRC} && \
	luarocks-${_LUA_DOT_VERSION} install --tree="${DESTDIR}${PREFIX}" --deps-mode=none digestif-${PKGVERSION_NOREV}-1.rockspec
	# remove luarocks-created root manifest
	${RM} ${DESTDIR}${PREFIX}/lib/luarocks/rocks-5.4/manifest

.include "../../lang/lua/application.mk"
.include "../../lang/lua/module.mk"
.include "../../mk/bsd.pkg.mk"
