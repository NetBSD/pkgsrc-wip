# $NetBSD: Makefile,v 1.1.1.1 2003/06/06 00:05:08 airhead Exp $
#

DISTNAME=	elvis-2.1_4
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.cs.pdx.edu/pub/elvis/

MAINTAINER=	airhead@sourceforge.net
HOMEPAGE=	http://elvis.the-little-red-haired-girl.org
COMMENT=	vi with regex search, hex editing, HTML and TeX previewing

USE_BUILDLINK2=		yes
GNU_CONFIGURE=		no
CONFIGURE_ARGS+=	--with-x=no --bindir=${PREFIX}/bin
CONFIGURE_ARGS+=	--datadir=${PREFIX}/share/elvis

LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

.include "../../mk/bsd.pkg.mk"
