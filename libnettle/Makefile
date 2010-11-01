# $NetBSD: Makefile,v 1.7 2010/11/01 17:00:23 emil_s Exp $

DISTNAME=	nettle-2.1
PKGNAME=	lib${DISTNAME}
CATEGORIES=	devel security
MASTER_SITES=	http://www.lysator.liu.se/~nisse/archive/ \
		ftp://ftp.lysator.liu.se/pub/security/lsh/

# created by cheusov@tut.by
MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.lysator.liu.se/~nisse/nettle/
COMMENT=	Cryptographic library

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"
SOEXT=dylib
.else
SOEXT=so
.endif

PLIST_SUBST+=		SOEXT=${SOEXT}

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-openssl --enable-shared

INFO_FILES=	yes
USE_TOOLS+=	gmake m4
TEST_TARGET=	check

.include "../../mk/bsd.pkg.mk"
