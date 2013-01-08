# $NetBSD: Makefile,v 1.15 2013/01/08 17:43:26 emil_s Exp $
#

DISTNAME=	task-2.1.2
CATEGORIES=	time
MASTER_SITES=	http://www.taskwarrior.org/download/

MAINTAINER=	esg@sdf.lonestar.org
HOMEPAGE=	http://taskwarrior.org/projects/show/taskwarrior/
COMMENT=	Task is an open source, command-line, TODO list manager
LICENSE=	gnu-gpl-v2

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

PKG_OPTIONS_VAR=	PKG_OPTIONS.task
PKG_SUPPORTED_OPTIONS=	lua
PKG_SUGGESTED_OPTIONS=	lua

.include "../../mk/bsd.options.mk"

INSTALLATION_DIRS+=	${PKGMANDIR}/man1 ${PKGMANDIR}/man5

CMAKE_ARGS+=	-DTASK_MAN1DIR=${PREFIX}/${PKGMANDIR}/man1
CMAKE_ARGS+=	-DTASK_MAN5DIR=${PREFIX}/${PKGMANDIR}/man5

.if !empty(PKG_OPTIONS:Mlua)
.include "../../lang/lua/buildlink3.mk"
.endif

.include "../../devel/libuuid/buildlink3.mk"
.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
