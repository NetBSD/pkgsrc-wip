# $NetBSD: Makefile,v 1.6 2005/11/19 16:42:08 rillig Exp $
#

DISTNAME=		tcd-2.2.0
CATEGORIES=		audio
MASTER_SITES=		http://savannah.gnu.org/download/tcd/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		roland.illig@gmx.de
HOMEPAGE=		http://savannah.gnu.org/download/tcd/
COMMENT=		Audio CD player using ncurses and SDL

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
INCOMPAT_CURSES+=	NetBSD-*-*

.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
