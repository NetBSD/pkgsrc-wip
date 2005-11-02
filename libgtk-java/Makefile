# $NetBSD: Makefile,v 1.3 2005/11/02 18:00:20 thomasklausner Exp $
#

DISTNAME=		libgtk-java-2.6.2
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/libgtk-java/2.6/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://java-gnome.sourceforge.net/
COMMENT=		Gtk2 bindings for Java

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake
CONFIGURE_ARGS+=	--without-gcj-compile

.include "../../x11/gtk2/buildlink3.mk"
.include "../../wip/mk/java-app.mk"
.include "../../mk/bsd.pkg.mk"
