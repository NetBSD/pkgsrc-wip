# $NetBSD: Makefile,v 1.5 2004/08/05 02:40:58 jlamwww Exp $

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

# Global and legacy options
.if defined(USE_PAM) || defined(USE_LIBCRACK)
.  if !defined(PKG_OPTIONS.shadow)
.    if defined(USE_PAM)
PKG_OPTIONS.shadow+=	PAM
.    endif
.    if defined(USE_LIBCRACK) && !empty(USE_LIBCRACK:M[yY][eE][sS])
PKG_OPTIONS.shadow+=	libcrack
.    endif
.  endif
.endif

###
### PAM support.
###
.if !empty(PKG_OPTIONS:MPAM)
.  include "../../security/PAM/buildlink3.mk"
CONFIGURE_ARGS+=	--with-libpam
.else
CONFIGURE_ARGS+=	--without-libpam
.endif

###
### Support using libcrack to protect against weak passwords.
###
.if !empty(PKG_OPTIONS:Mlibcrack)
.  include "../../security/libcrack/buildlink3.mk"
CONFIGURE_ARGS+=	--with-libcrack
.else
CONFIGURE_ARGS+=	--without-libcrack
.endif

.include "../../mk/bsd.pkg.mk"
