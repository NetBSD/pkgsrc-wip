# $NetBSD: Makefile,v 1.4 2003/12/09 17:26:28 airhead Exp $
#

DISTNAME=	elvis-2.2_0
PKGNAME=        elvis-x11-2.2.0
CATEGORIES=	editors x11
MASTER_SITES=	ftp://ftp.cs.pdx.edu/pub/elvis/

MAINTAINER=	airhead@users.sourceforge.net
HOMEPAGE=	http://elvis.vi-editor.org/
COMMENT=	GUI for elvis, includes console elvis

CONFLICTS=	elvis-[0-9]*

HAS_CONFIGURE=		YES
USE_X11=		YES
USE_X11BASE=		YES
CONFIGURE_ARGS+=	--with-x=yes
CONFIGURE_ARGS+=	--prefix=${X11PREFIX}

.include "../../mk/bsd.pkg.mk"
