# $NetBSD: Makefile,v 1.3 2005/08/01 06:14:51 scode Exp $

DISTNAME=		moc-2.3.0
CATEGORIES=		audio
MASTER_SITES=		ftp://ftp.daper.net/pub/soft/moc/stable/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		peter.schuller@infidyne.com
HOMEPAGE=		http://moc.daper.net/
COMMENT=		Curses based console audio player

GNU_CONFIGURE=		YES

# We require ncurses because with curses arrow key navigation is buggy
CONFIGURE_ARGS+=        --with-ncurses
USE_NCURSES=            YES

.include "../../devel/ncurses/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../audio/speex/buildlink3.mk"
.include "../../audio/libid3tag/buildlink3.mk"
.include "../../audio/libmad/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/flac/buildlink3.mk"
.include "../../audio/libsndfile/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
