# $NetBSD: Makefile,v 1.2 2004/05/04 02:57:13 blef Exp $

DISTNAME=	libdv-0.101
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libdv/}

MAINTAINER=	tech-pkg-ja@jp.NetBSD.org
HOMEPAGE=	http://libdv.sourceforge.net/
COMMENT=	a GPL codec for DV video

USE_BUILDLINK3=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--prefix=${PREFIX}

.include "../../mk/bsd.prefs.mk"
.if empty(MACHINE_PLATFORM:MNetBSD-*-i386)
CONFIGURE_ARGS+=--disable-asm
.endif

#if Xfree86 < ver. 4.x.x, uncomment 
#CONFIGURE_ARGS+=--disable-xv

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
