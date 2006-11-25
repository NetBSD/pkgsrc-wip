# $NetBSD: Makefile,v 1.5 2006/11/25 11:51:00 shattered Exp $
#

DISTNAME=		uade-1.00
CATEGORIES=		audio
MASTER_SITES=		http://uade.ton.tut.fi/uade/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://uade.ton.tut.fi/
COMMENT=		Unix Amiga Delitracker Emulator

USE_PKGLOCALEDIR=	yes
HAS_CONFIGURE=		yes

CONFIGURE_ARGS=		--with-oss --without-xmms --without-bmp --prefix=${PREFIX:Q}

.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
