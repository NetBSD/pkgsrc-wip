# $NetBSD: Makefile,v 1.9 2003/12/09 17:10:11 airhead Exp $
#

DISTNAME=	elvis-2.2_0
PKGNAME=        elvis-2.2.0
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.cs.pdx.edu/pub/elvis/

MAINTAINER=	airhead@users.sourceforge.net
HOMEPAGE=	http://elvis.vi-editor.org/
COMMENT=	Vi clone with regex search, hex editing, HTML and TeX previewing

HAS_CONFIGURE=		YES
CONFIGURE_ARGS+=	--with-x=no
CONFIGURE_ARGS+=	--prefix=${PREFIX}

.include "../../mk/bsd.pkg.mk"
