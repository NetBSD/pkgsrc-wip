# $NetBSD: Makefile,v 1.4 2004/04/07 20:26:53 jeremy-c-reed Exp $

DISTNAME=		shadow-4.0.3
PKGREVISION=		3
CATEGORIES=		sysutils devel
MASTER_SITES=		ftp://ftp.pld.org.pl/software/shadow/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://shadow.pld.org.pl/
COMMENT=		User administration and passwd database tools for Linux

ONLY_FOR_PLATFORM=	Linux-*-* # Linux shadow format

USE_BUILDLINK3=		YES
GNU_CONFIGURE=		YES

.include "../../mk/bsd.prefs.mk"

.if defined(USE_PAM)
CONFIGURE_ARGS+=	--with-libpam
.include "../../security/PAM/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-libpam
.endif

.if ${USE_LIBCRACK} == YES
.  include "../../security/libcrack/buildlink3.mk"
CONFIGURE_ARGS+=	--with-libcrack
.else
CONFIGURE_ARGS+=	--without-libcrack
.endif

.include "../../mk/bsd.pkg.mk"
