# $NetBSD: Makefile,v 1.3 2004/06/11 21:23:24 jeremy-c-reed Exp $

DISTNAME=	libdv-0.102
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libdv/}

MAINTAINER=	tech-pkg-ja@jp.NetBSD.org
HOMEPAGE=	http://libdv.sourceforge.net/
COMMENT=	Quasar DV codec for digital video

USE_BUILDLINK3=		yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE+=     ${WRKSRC}/libdv.pc.in

# XXX workaround build problem, make sure -O is defined
# XXX this needs to be improved to not reset -O2 for example
CFLAGS+=		-O

.include "../../mk/bsd.prefs.mk"
.if empty(MACHINE_PLATFORM:MNetBSD-*-i386)
CONFIGURE_ARGS+=	--disable-asm
.endif

#if Xfree86 < ver. 4.x.x, uncomment 
#CONFIGURE_ARGS+=	--disable-xv

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

# work-around bug where -O is not defined
# Or use  ${CFLAGS:N-O0}
CFLAGS:=        ${CFLAGS:C/-O0//g}
