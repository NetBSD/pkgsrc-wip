# $NetBSD: Makefile,v 1.2 2004/11/03 10:13:55 adrian_p Exp $

DISTNAME=	tre-0.7.0
CATEGORIES=	devel
MASTER_SITES=	http://laurikari.net/tre/

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://laurikari.net/tre/
COMMENT=	Lightweight and robust POSIX compliant regexp matching library

GNU_CONFIGURE=		YES
USE_BUILDLINK3=		YES

CONFIGURE_ARGS+=	--disable-agrep
CONFIGURE_ARGS+=	--disable-shared
CONFIGURE_ARGS+=	--disable-system-abi
CONFIGURE_ARGS+=	--disable-wchar
CONFIGURE_ARGS+=	--disable-multibyte

.include "../../mk/bsd.pkg.mk"
