# $NetBSD: Makefile,v 1.2 2007/08/15 22:16:03 shindenmorr Exp $

DISTNAME=	libgadu-1.7.1
CATEGORIES=	chat
MASTER_SITES=	http://toxygen.net/libgadu/files/

MAINTAINER=	mjl@luckie.org.nz
HOMEPAGE=	http://dev.null.pl/ekg/
COMMENT=	Used by Instant Messengers with Gadu-Gadu support

USE_TOOLS+=		autoconf automake gmake aclocal autoheader
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
CONFIGURE_ARGS+=	--without-openssl --enable-shared

pre-configure:
	cd ${WRKSRC:Q} && aclocal -I m4 && autoheader && autoconf

.include "../../mk/bsd.pkg.mk"
