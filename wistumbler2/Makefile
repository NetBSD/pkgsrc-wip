# $NetBSD: Makefile,v 1.1.1.1 2003/11/18 15:39:05 poppnk Exp $

DISTNAME=	wistumbler2.00-pre3
PKGNAME=	wistumbler-2.00-pre3
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.nopcode.org/prj/wistumbler2/

MAINTAINER=	pancake@phreaker.net
HOMEPAGE=	http://www.nopcode.org/?t=wistumbler2
COMMENT=	Fork of original WaveLAN/IEEE network stumbler

USE_BUILDLINK2=	YES
USE_X11=	YES
GNU_CONFIGURE=	YES
MANCOMPRESSED=	YES

NOT_FOR_PLATFORM=	NetBSD-[01].[012345]*-* 
ONLY_FOR_PLATFORM=	NetBSD-*-* FreeBSD-*-*

.include "../../mk/bsd.prefs.mk"
.if ! empty(WISTUMBLER2_USE_GTK:M[Nn][Oo])
CONFIGURE_ENV+=USE_GTK=0
.else
.include "../../x11/gtk2/buildlink2.mk"
.endif
.include "../../mk/bsd.pkg.mk"
