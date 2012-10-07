# $NetBSD: Makefile,v 1.6 2012/10/07 17:41:39 asau Exp $
#

DISTNAME=		uade-1.00
CATEGORIES=		audio
MASTER_SITES=		http://uade.ton.tut.fi/uade/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://uade.ton.tut.fi/
COMMENT=		Unix Amiga Delitracker Emulator

PKG_DESTDIR_SUPPORT=	none

USE_PKGLOCALEDIR=	yes
HAS_CONFIGURE=		yes

CONFIGURE_ARGS=		--with-oss --without-xmms --without-bmp --prefix=${PREFIX:Q}

.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
