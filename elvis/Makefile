# $NetBSD: Makefile,v 1.6 2003/06/10 11:15:37 airhead Exp $
#

PKGNAME=        elvis-2.1.4
DISTNAME=	elvis-2.1_4
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.cs.pdx.edu/pub/elvis/

MAINTAINER=	airhead@sourceforge.net
HOMEPAGE=	http://elvis.the-little-red-haired-girl.org
COMMENT=	vi with regex search, hex editing, HTML and TeX previewing

HAS_CONFIGURE=		YES
CONFIGURE_ARGS+=	--with-x=no
CONFIGURE_ARGS+=	--bindir=${PREFIX}/bin
CONFIGURE_ARGS+=	--datadir=${PREFIX}/share/elvis

.include "../../mk/bsd.pkg.mk"
