# $NetBSD: Makefile,v 1.4 2005/04/11 21:16:05 tvierling Exp $

DISTNAME=	tre-0.7.2
CATEGORIES=	devel
MASTER_SITES=	http://laurikari.net/tre/

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://laurikari.net/tre/
COMMENT=	Lightweight and robust POSIX compliant regexp matching library

GNU_CONFIGURE=		YES

CONFIGURE_ARGS+=	--disable-agrep
CONFIGURE_ARGS+=	--disable-shared
CONFIGURE_ARGS+=	--disable-system-abi
CONFIGURE_ARGS+=	--disable-wchar
CONFIGURE_ARGS+=	--disable-multibyte

.include "../../mk/bsd.pkg.mk"
