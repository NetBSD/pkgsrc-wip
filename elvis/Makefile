# $NetBSD: Makefile,v 1.10 2003/12/09 18:59:25 airhead Exp $
#

DISTNAME=	elvis-2.2_0
PKGNAME=        elvis-2.2.0
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.cs.pdx.edu/pub/elvis/

MAINTAINER=	airhead@users.sourceforge.net
HOMEPAGE=	http://elvis.vi-editor.org/
COMMENT=	Vi clone with regex search, hex editing, HTML and TeX previewing

CONFLICTS+=	elvis-x11[0-9]*

HAS_CONFIGURE=		YES
CONFIGURE_ARGS+=	--with-x=no
CONFIGURE_ARGS+=	--prefix=${PREFIX}

.include "../../mk/bsd.pkg.mk"
