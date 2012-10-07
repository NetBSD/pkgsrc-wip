# $NetBSD: Makefile,v 1.14 2012/10/07 17:17:23 asau Exp $
#

DISTNAME=	task-1.9.4
CATEGORIES=	time
MASTER_SITES=	http://www.taskwarrior.org/download/

MAINTAINER=	esg@sdf.lonestar.org
HOMEPAGE=	http://taskwarrior.org/projects/show/taskwarrior/
COMMENT=	Task is an open source, command-line, TODO list manager
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++

PKG_OPTIONS_VAR=	PKG_OPTIONS.task
PKG_SUPPORTED_OPTIONS=	ncurses
PKG_SUGGESTED_OPTIONS=	ncurses

.include "../../mk/bsd.options.mk"

.if empty(PKG_OPTIONS:Mncurses)
CONFIGURE_ARGS+=	--without-ncurses
.endif


INSTALLATION_DIRS+=	${PKGMANDIR}/man1 ${PKGMANDIR}/man5

.if !empty(PKG_OPTIONS:Mncurses)
.include "../../devel/ncurses/buildlink3.mk"
.endif

.include "../../mk/bsd.pkg.mk"
