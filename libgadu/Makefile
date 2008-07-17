# $NetBSD: Makefile,v 1.3 2008/07/17 17:05:50 shindenmorr Exp $

DISTNAME=	libgadu-1.8.1
CATEGORIES=	chat
MASTER_SITES=	http://toxygen.net/libgadu/files/

MAINTAINER=	mjl@luckie.org.nz
HOMEPAGE=	http://dev.null.pl/ekg/
COMMENT=	Used by Instant Messengers with Gadu-Gadu support

USE_TOOLS+=		autoconf automake gmake aclocal autoheader
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
CONFIGURE_ARGS+=	--without-openssl --enable-shared

.include "../../mk/bsd.pkg.mk"
