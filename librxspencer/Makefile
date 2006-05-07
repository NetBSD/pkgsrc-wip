# $NetBSD: Makefile,v 1.1 2006/05/07 14:21:24 cheusov Exp $

DISTNAME=	rxspencer-alpha3.8.g3
PKGNAME=	librxspencer-3.8.3
CATEGORIES=	devel
MASTER_SITES=	http://arglist.com/regex/

MAINTAINER=	cheusov@tut.by
HOMEPAGE=	http://arglist.com/regex/
COMMENT=	POSIX API regexp library by Henry Spencer

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--enable-shared

TEST_TARGET=		check

.include "../../mk/bsd.pkg.mk"
