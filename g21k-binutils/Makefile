# $NetBSD: Makefile,v 1.2 2004/08/17 22:08:45 thomasklausner Exp $
#

DISTNAME=		g21k-binutils-PL4
PKGNAME=		g21k-binutils-0.4
CATEGORIES=		lang
MASTER_SITES=	ftp://ftp.kvaleberg.com/pub/

MAINTAINER=		ianzag@mail.ru
HOMEPAGE=		http://www.kvaleberg.com/g21.html
COMMENT=		Assemblre and linker tools for Analog Devices 21k series DSPs

USE_GNU_TOOLS+=	make
GNU_CONFIGURE=	YES
CONFIGURE_ARGS+= --with-adidsp=${PREFIX}

.include "../../mk/bsd.pkg.mk"
