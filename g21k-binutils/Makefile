# $NetBSD: Makefile,v 1.5 2010/11/11 22:42:06 shattered Exp $
#

DISTNAME=		g21k-binutils-PL4
PKGNAME=		g21k-binutils-0.4
CATEGORIES=		lang
MASTER_SITES=		ftp://ftp.kvaleberg.org/pub/

MAINTAINER=		ianzag@mail.ru
HOMEPAGE=		http://www.kvaleberg.org/g21.html
COMMENT=		Assemblre and linker tools for Analog Devices 21k series DSPs

USE_TOOLS+=	gmake
GNU_CONFIGURE=	YES
CONFIGURE_ARGS+= --with-adidsp=${PREFIX:Q}

.include "../../mk/bsd.pkg.mk"
