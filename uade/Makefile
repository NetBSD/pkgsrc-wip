# $NetBSD: Makefile,v 1.1.1.1 2004/11/03 18:49:25 poppnk Exp $
#

DISTNAME=		uade-1.00
CATEGORIES=		wip audio
MASTER_SITES=		http://uade.ton.tut.fi/uade/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://uade.ton.tut.fi/
COMMENT=		Unix Amiga Delitracker Emulator

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
HAS_CONFIGURE=		yes

CONFIGURE_ARGS=--with-oss --without-xmms --without-bmp --prefix=${PREFIX}

.include "../../mk/bsd.pkg.mk"
