# $NetBSD: Makefile,v 1.6 2012/09/29 00:50:33 asau Exp $
#

DISTNAME=		g21k-binutils-PL4
PKGNAME=		g21k-binutils-0.4
CATEGORIES=		lang
MASTER_SITES=		ftp://ftp.kvaleberg.org/pub/

MAINTAINER=		ianzag@mail.ru
HOMEPAGE=		http://www.kvaleberg.org/g21.html
COMMENT=		Assemblre and linker tools for Analog Devices 21k series DSPs


USE_TOOLS+=		gmake
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--with-adidsp=${PREFIX}

.include "../../mk/bsd.pkg.mk"
