# $NetBSD: Makefile,v 1.1.1.1 2005/03/07 09:21:48 jeremy-c-reed Exp $
#
# TODO: install docs, license

DISTNAME=		poppler-0.1.1
CATEGORIES=		print
MASTER_SITES=		http://freedesktop.org/~krh/

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://poppler.freedesktop.org/
COMMENT=		PDF rendering library

USE_BUILDLINK3=		yes
#USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
#PKGCONFIG_OVERRIDE+=	${WRKSRC}/poppler-cairo.pc.in
#PKGCONFIG_OVERRIDE+=	${WRKSRC}/poppler-splash.pc.in
PKGCONFIG_OVERRIDE+=	${WRKSRC}/poppler.pc.in
GNU_CONFIGURE=		yes

# Don't build the Splash graphics backend.
CONFIGURE_ARGS+=	--disable-splash-output
# Don't build the cairo graphics backend.
CONFIGURE_ARGS+=	--disable-cairo-output
# Don't compile GTK+ test program.
CONFIGURE_ARGS+=	--disable-gtk-test

.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
