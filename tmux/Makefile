# $NetBSD: Makefile,v 1.12 2009/02/17 18:45:20 fulviociriaco Exp $

DISTNAME=	tmux-0.7
PKGREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tmux/}

MAINTAINER=	oivulf@gmail.com
HOMEPAGE=	http://tmux.sourceforge.net/
COMMENT=	BSD-licensed terminal multiplexer (GNU Screen alternative)

PKG_DESTDIR_SUPPORT=	user-destdir

NO_CONFIGURE=	yes
USE_NCURSES=	yes

INSTALL_MAKE_FLAGS+= \
   INSTALL_MAN=${INSTALL_MAN:Q} \
   INSTALL_MAN_DIR=${INSTALL_PROGRAM_DIR:Q} \
   INSTALL_PROGRAM_DIR=${INSTALL_PROGRAM_DIR:Q} \
   INSTALL_PROGRAM=${INSTALL_PROGRAM:Q}

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
