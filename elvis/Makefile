# $NetBSD: Makefile,v 1.8 2003/11/05 12:49:31 airhead Exp $
#

DISTNAME=	elvis-2.1_4
PKGNAME=        elvis-2.1.4
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.cs.pdx.edu/pub/elvis/

MAINTAINER=	airhead@users.sourceforge.net
HOMEPAGE=	http://elvis.the-little-red-haired-girl.org
COMMENT=	vi with regex search, hex editing, HTML and TeX previewing

HAS_CONFIGURE=		YES
CONFIGURE_ARGS+=	--with-x=no
CONFIGURE_ARGS+=	--bindir=${PREFIX}/bin
CONFIGURE_ARGS+=	--datadir=${PREFIX}/share/elvis

.include "../../mk/bsd.pkg.mk"
