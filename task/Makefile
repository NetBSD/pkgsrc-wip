# $NetBSD: Makefile,v 1.10 2010/07/21 06:26:05 emil_s Exp $
#

DISTNAME=	task-1.9.2
CATEGORIES=	time
MASTER_SITES=	http://www.taskwarrior.org/download/

MAINTAINER=	emil@math.su.se
HOMEPAGE=	http://taskwarrior.org/projects/show/taskwarrior/
COMMENT=	Task is an open source, command-line, TODO list manager
#LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++

.include "../../mk/bsd.prefs.mk"

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
