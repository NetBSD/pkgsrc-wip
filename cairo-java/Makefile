# $NetBSD: Makefile,v 1.1.1.1 2006/02/09 11:16:49 poppnk Exp $
#

DISTNAME=		cairo-java-1.0.1
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/cairo-java/1.0/}

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://java-gnome.sourceforge.net/
COMMENT=		Cairo bindings for Java

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake
CONFIGURE_ARGS+=	--without-gcj-compile JAVAC=javac

.include "../../graphics/cairo/buildlink3.mk"
.include "../../wip/glib-java/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../wip/mk/java-app.mk"
.include "../../mk/java-env.mk"
.include "../../mk/bsd.pkg.mk"
