# $NetBSD: Makefile,v 1.3 2005/07/08 20:00:32 jeremy-c-reed Exp $
#
# TODO: install docs, license

DISTNAME=		poppler-0.3.3
CATEGORIES=		print
MASTER_SITES=		http://poppler.freedesktop.org/

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://poppler.freedesktop.org/
COMMENT=		PDF rendering library

USE_TOOLS=		gmake
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
#PKGCONFIG_OVERRIDE+=	${WRKSRC}/poppler-cairo.pc.in
PKGCONFIG_OVERRIDE+=	${WRKSRC}/poppler-glib.pc.in
PKGCONFIG_OVERRIDE+=	${WRKSRC}/poppler-splash.pc.in
PKGCONFIG_OVERRIDE+=	${WRKSRC}/poppler.pc.in
GNU_CONFIGURE=		yes

# TODO: Later add an option to choose Splash versus Cairo backend.
## Don't build the Splash graphics backend.
#CONFIGURE_ARGS+=	--disable-splash-output
# Don't build the cairo graphics backend.
CONFIGURE_ARGS+=	--disable-cairo-output
# Don't compile poppler qt wrapper.
CONFIGURE_ARGS+=	--disable-poppler-qt
# Don't compile GTK+ test program.
CONFIGURE_ARGS+=	--disable-gtk-test
# TODO: check papersize?
#  --enable-a4-paper       use A4 paper size instead of Letter for PostScript output
# maybe  glib wrapper is only part needing gtk??
#  --disable-poppler-glib  Don't compile poppler glib wrapper.

.include "../../devel/glib2/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
