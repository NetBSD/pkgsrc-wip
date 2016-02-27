# $NetBSD: Makefile,v 1.16 2015/08/10 21:16:48 yhardy Exp $
#

DISTNAME=	task-2.5.1
CATEGORIES=	time
MASTER_SITES=	http://www.taskwarrior.org/download/

MAINTAINER=	esg@sdf.lonestar.org
HOMEPAGE=	http://taskwarrior.org/projects/show/taskwarrior/
COMMENT=	Task is an open source, command-line, TODO list manager
LICENSE=	gnu-gpl-v2

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

#GCC_REQD+=	4.7

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
.include "../../security/gnutls/buildlink3.mk"
.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
