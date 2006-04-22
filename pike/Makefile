# $NetBSD: Makefile,v 1.1 2006/04/22 15:26:38 rillig Exp $
#

DISTNAME=		Pike-v7.6.66
PKGNAME=		pike-7.6.66
CATEGORIES=		lang
MASTER_SITES=		http://pike.ida.liu.se/pub/pike/latest-stable/

MAINTAINER=		rillig@NetBSD.org
HOMEPAGE=		http://pike.ida.liu.se/pub/pike/latest-stable/
COMMENT=		Dynamic programming language similar to Java and C

GNU_CONFIGURE=		yes
CONFIGURE_DIRS=		src
BUILD_TARGET=		pike #all
CONFIGURE_ARGS+=	--without-nettle

.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
