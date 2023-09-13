# $NetBSD: Makefile,v 1.18 2015/09/13 07:33:05 thomasklausner Exp $

DISTNAME=	tmux-3.3a
CATEGORIES=	games
GIT_REPO=	https://github.com/tmux/tmux.git

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/tmux/tmux
COMMENT=	Terminal multiplexer
LICENSE=	public-domain # actually, dwtfywtpl

USE_LANGUAGES=	c
USE_TOOLS+=	autoconf automake pkg-config

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-sixel

pre-configure:
	cd ${WRKSRC} && autoreconf -fiv

.include "../../mk/curses.buildlink3.mk"
.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
