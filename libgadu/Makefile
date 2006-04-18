# $NetBSD: Makefile,v 1.1.1.1 2006/04/18 21:51:43 matthewluckie Exp $

DISTNAME=	libgadu-20051229
CATEGORIES=	chat
MASTER_SITES=	http://bsdguru.org/distfiles/

MAINTAINER=	mjl@luckie.org.nz
HOMEPAGE=	http://dev.null.pl/ekg/
COMMENT=	Used by Instant Messengers with Gadu-Gadu support

USE_TOOLS+=		autoconf automake gmake
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-openssl --enable-shared

pre-configure:
	cd ${WRKSRC:Q} && aclocal -I m4 && autoheader && autoconf

.include "../../mk/bsd.pkg.mk"
