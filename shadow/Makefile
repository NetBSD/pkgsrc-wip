# $NetBSD: Makefile,v 1.1.1.1 2003/12/04 00:20:47 jeremy-c-reed Exp $

DISTNAME=		shadow-4.0.3
PKGREVISION=		2
CATEGORIES=		sysutils devel
MASTER_SITES=		ftp://ftp.pld.org.pl/software/shadow/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://shadow.pld.org.pl/
COMMENT=		User administration and passwd database tools for Linux

ONLY_FOR_PLATFORM=	Linux-*-* # Linux shadow format

GNU_CONFIGURE=		YES
# because the ./configure sets it to PREFIX/share/man
CONFIGURE_ARGS+=	--mandir=${PREFIX}/man

.include "../../mk/bsd.prefs.mk"

.if defined(USE_PAM)
CONFIGURE_ARGS+=	--with-libpam
.include "../../security/linux-pam/buildlink2.mk"
.else
CONFIGURE_ARGS+=	--without-libpam
.endif

.if ${USE_LIBCRACK} == YES
.  include "../../security/libcrack/buildlink2.mk"
CONFIGURE_ARGS+=	--with-libcrack
.else
CONFIGURE_ARGS+=	--without-libcrack
.endif

.include "../../mk/bsd.pkg.mk"
