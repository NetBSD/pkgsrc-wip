# $NetBSD: Makefile,v 1.3 2006/05/31 21:37:32 poppnk Exp $
#

DISTNAME=		glib-java-0.2.5
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/glib-java/0.2/}

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://java-gnome.sourceforge.net/
COMMENT=		Glib bindings for Java

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake pkg-config
CONFIGURE_ARGS+=	--without-gcj-compile JAVAC="javac"

.include "../../devel/glib2/buildlink3.mk"
.include "../../wip/mk/java-app.mk"
.include "../../mk/bsd.pkg.mk"
