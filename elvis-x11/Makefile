# $NetBSD: Makefile,v 1.2 2003/11/05 12:51:15 airhead Exp $
#

DISTNAME=	elvis-2.1_4
PKGNAME=        elvis-x11-2.1.4
CATEGORIES=	editors x11
MASTER_SITES=	ftp://ftp.cs.pdx.edu/pub/elvis/

MAINTAINER=	airhead@users.sourceforge.net
HOMEPAGE=	http://elvis.the-little-red-haired-girl.org
COMMENT=	GUI for elvis, includes console elvis

CONFLICTS=	elvis-[0-9]*

HAS_CONFIGURE=		YES
USE_X11=		YES
USE_X11BASE=		YES
CONFIGURE_ARGS+=	--with-x=yes
CONFIGURE_ARGS+=	--x-libraries=${X11BASE}/lib
CONFIGURE_ARGS+=	--x-includes=${X11BASE}/include
CONFIGURE_ARGS+=	--bindir=${X11PREFIX}/bin
CONFIGURE_ARGS+=	--datadir=${X11PREFIX}/share/elvis

.include "../../mk/bsd.pkg.mk"
