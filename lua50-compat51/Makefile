# $NetBSD: Makefile,v 1.2 2007/06/01 18:00:08 hoka_adam Exp $

DISTNAME=	compat-5.1r5
PKGNAME=	lua50-compat51-5.1.5
CATEGORIES=	devel
MASTER_SITES=	http://luaforge.net/frs/download.php/1410/

MAINTAINER=	adam.hoka@gmail.com
COMMENT=	Lua 5.1 package compatibility layer for Lua 5.0.x

SUBST_CLASSES+=			fix-paths-in-sh
SUBST_STAGE.fix-paths-in-sh=	pre-configure
SUBST_MESSAGE.fix-paths-in-sh=	Fixing absolute paths.
SUBST_FILES.fix-paths-in-sh=	lua50c51.sh
SUBST_SED.fix-paths-in-sh=	-e "s:/usr/local:${PREFIX}:g"

post-extract:
	${CP} ${FILESDIR}/lua50c51.sh ${WRKSRC}

do-build:
	@${ECHO} "Nothing to build."

do-install:
	${INSTALL_DATA_DIR} -p ${PREFIX}/lib/lua/${DISTNAME}
	${INSTALL_DATA} ${WRKSRC}/compat-5.1.lua ${PREFIX}/share/lua/5.0
	${INSTALL_DATA} ${WRKSRC}/compat-5.1.c ${PREFIX}/lib/lua/${DISTNAME}
	${INSTALL_DATA} ${WRKSRC}/compat-5.1.h ${PREFIX}/lib/lua/${DISTNAME}
	${INSTALL_SCRIPT} ${WRKSRC}/lua50c51.sh ${PREFIX}/bin/lua50c51

.include "../../wip/lua50/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
