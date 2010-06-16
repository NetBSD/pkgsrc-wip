# $NetBSD: Makefile,v 1.1.1.1 2010/06/16 21:36:57 christtrekker Exp $
#

DISTNAME=	fltk-1.3.x-r7637
CATEGORIES=	x11
MASTER_SITES+=	http://ftp.easysw.com/pub/fltk/snapshots/
MASTER_SITES+=	http://ftp2.easysw.com/pub/fltk/snapshots/
MASTER_SITES+=	http://ftp.funet.fi/pub/mirrors/ftp.easysw.com/pub/fltk/snapshots/

MAINTAINER=	christtrekker@users.sourceforge.net
HOMEPAGE=	http://fltk.org/
COMMENT=	Fast Light Tool Kit for graphical user interfaces
LICENSE=	gnu-lgpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++

.include "../../mk/x11.buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
