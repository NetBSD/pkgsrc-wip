# $NetBSD: Makefile,v 1.1.1.1 2004/03/27 22:46:01 xtraeme Exp $

DISTNAME=	libdv-0.101
CATEGORIES=	graphics
MASTER_SITES=	http://keihanna.dl.sourceforge.net/sourceforge/libdv/

MAINTAINER=	tech-pkg-ja@jp.NetBSD.org
HOMEPAGE=	http://libdv.sourceforge.net/
COMMENT=	a GPL codec for DV video

USE_BUILDLINK2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--prefix=${PREFIX}

.include "../../mk/bsd.prefs.mk"
.if empty(MACHINE_PLATFORM:MNetBSD-*-i386)
CONFIGURE_ARGS+=--disable-asm
.endif

#if Xfree86 < ver. 4.x.x, uncomment 
#CONFIGURE_ARGS+=--disable-xv

.include "../../converters/libiconv/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/glib/buildlink2.mk"
.include "../../devel/popt/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/ossaudio.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
