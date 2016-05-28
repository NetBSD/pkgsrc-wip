# $NetBSD: Makefile,v 1.9 2012/11/25 23:32:26 othyro Exp $
#

DISTNAME=		libgtk-java-2.8.5
PKGREVISION=		1
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/libgtk-java/2.8/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://java-gnome.sourceforge.net/
COMMENT=		Gtk2 bindings for Java


GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake pkg-config
CONFIGURE_ARGS+=	--without-gcj-compile JAVAC=javac

.include "../../wip/glib-java/buildlink3.mk"
.include "../../wip/cairo-java/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../wip/mk/java-app.mk"
.include "../../mk/bsd.pkg.mk"
