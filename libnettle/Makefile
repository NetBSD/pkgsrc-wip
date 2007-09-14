# $NetBSD: Makefile,v 1.4 2007/09/14 06:44:49 cheusov Exp $

DISTNAME=	nettle-1.14
PKGNAME=	lib${DISTNAME}
CATEGORIES=	devel security
MASTER_SITES=	http://www.lysator.liu.se/~nisse/archive/ \
		ftp://ftp.lysator.liu.se/pub/security/lsh/

# created by cheusov@tut.by
MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.lysator.liu.se/~nisse/nettle/
COMMENT=	Cryptographic library

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-openssl --enable-shared

INFO_FILES=	yes
USE_TOOLS+=	gmake m4
TEST_TARGET=	check

.include "../../mk/bsd.pkg.mk"
