# $NetBSD: Makefile,v 1.1.1.1 2007/06/01 20:16:15 hoka_adam Exp $

DISTNAME=	bsdinstaller-20070528
PKGNAME=	dfuibe_lua-1.0
CATEGORIES=	sysutils

MASTER_SITES=   http://rnrdoctor.sytes.net/~replaced/bsdinstaller/
WRKSRC=         ${WRKDIR}/${DISTNAME}/installer/src/backend/lua

MAINTAINER=	adam.hoka@gmail.com
COMMENT=	DFUI Lua backend

FILESDIR=	${.CURDIR}/../../wip/bsdinstaller/files

DFUIBE_LUA_DIR=	${PREFIX}/share/dfuibe_lua

pre-configure:
	${CP} ${FILESDIR}/Config ${WRKDIR}/${DISTNAME}/installer/src/Config

do-install:
	${INSTALL_DATA_DIR} ${DFUIBE_LUA_DIR}
	${INSTALL_DATA_DIR} ${DFUIBE_LUA_DIR}/lib
	${INSTALL_DATA_DIR} ${DFUIBE_LUA_DIR}/conf
	${INSTALL_DATA_DIR} ${DFUIBE_LUA_DIR}/pit
	${INSTALL_DATA_DIR} ${DFUIBE_LUA_DIR}/install
	${INSTALL_DATA_DIR} ${DFUIBE_LUA_DIR}/configure
	${INSTALL_DATA_DIR} ${DFUIBE_LUA_DIR}/configure/menu
	${INSTALL_DATA_DIR} ${DFUIBE_LUA_DIR}/upgrade
	${INSTALL_DATA_DIR} ${DFUIBE_LUA_DIR}/netboot
	${INSTALL_DATA} -o root -g wheel -m 444 ${WRKSRC}/*.lua ${DFUIBE_LUA_DIR}/
	${INSTALL_DATA} -o root -g wheel -m 444 ${WRKSRC}/lib/*.lua ${DFUIBE_LUA_DIR}/lib/
	${INSTALL_DATA} -o root -g wheel -m 444 ${WRKSRC}/conf/*.lua ${DFUIBE_LUA_DIR}/conf/
	${INSTALL_DATA} -o root -g wheel -m 444 ${WRKSRC}/pit/*.lua ${DFUIBE_LUA_DIR}/pit/
	${INSTALL_DATA} -o root -g wheel -m 444 ${WRKSRC}/install/*.lua ${DFUIBE_LUA_DIR}/install/
	${INSTALL_DATA} -o root -g wheel -m 444 ${WRKSRC}/configure/*.lua ${DFUIBE_LUA_DIR}/configure/
	${INSTALL_DATA} -o root -g wheel -m 444 ${WRKSRC}/configure/menu/*.lua ${DFUIBE_LUA_DIR}/configure/menu/
	${INSTALL_DATA} -o root -g wheel -m 444 ${WRKSRC}/upgrade/*.lua ${DFUIBE_LUA_DIR}/upgrade/
	${INSTALL_DATA} -o root -g wheel -m 444 ${WRKSRC}/netboot/*.lua ${DFUIBE_LUA_DIR}/netboot/

.include "../../wip/lua50/buildlink3.mk"
.include "../../wip/lua50-pty/buildlink3.mk"
.include "../../wip/lua50-dfui/buildlink3.mk"
.include "../../wip/lua50-app/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
