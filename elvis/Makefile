# $NetBSD: Makefile,v 1.5 2003/06/07 11:05:56 airhead Exp $
#

PKGNAME=        elvis-2.1.4
DISTNAME=	elvis-2.1_4
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.cs.pdx.edu/pub/elvis/

MAINTAINER=	airhead@sourceforge.net
HOMEPAGE=	http://elvis.the-little-red-haired-girl.org
COMMENT=	vi with regex search, hex editing, HTML and TeX previewing

USE_BUILDLINK2=		yes
HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-x=no
CONFIGURE_ARGS+=	--bindir=${PREFIX}/bin
CONFIGURE_ARGS+=	--datadir=${PREFIX}/share/elvis

.include "../../mk/bsd.pkg.mk"
