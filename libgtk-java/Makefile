# $NetBSD: Makefile,v 1.2 2005/05/24 10:30:35 rillig Exp $
#

DISTNAME=		libgtk-java-2.6.2
CATEGORIES=		wip x11
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
