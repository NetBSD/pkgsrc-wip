# $NetBSD: Makefile,v 1.5 2005/09/17 19:21:14 xtraeme Exp $

DISTNAME=		moc-2.3.1
CATEGORIES=		audio
MASTER_SITES=		ftp://ftp.daper.net/pub/soft/moc/stable/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		peter.schuller@infidyne.com
HOMEPAGE=		http://moc.daper.net/
COMMENT=		Curses based console audio player

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_NCURSES=		yes

# We require ncurses because with curses arrow key navigation is buggy
CONFIGURE_ARGS+=        --with-ncurses

.include "options.mk"

.include "../../audio/libid3tag/buildlink3.mk"
.include "../../audio/libmad/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
