# $NetBSD: Makefile,v 1.4 2012/10/05 11:31:52 asau Exp $

DISTNAME=		Pike-v8.0.702
PKGNAME=		${DISTNAME:tl:S/-v//}
CATEGORIES=		lang
MASTER_SITES=		http://pike.lysator.liu.se/pub/pike/latest-stable/
LICENSE=		gnu-gpl-v2 AND gnu-lgpl-v2.1 AND mpl-1.1

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://pike.lysator.liu.se/
COMMENT=		Dynamic programming language similar to Java and C

GNU_CONFIGURE=		yes
CONFIGURE_DIRS=		src
BUILD_TARGET=		pike #all
CONFIGURE_ARGS+=	--without-nettle

.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
