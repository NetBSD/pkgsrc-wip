# $NetBSD: Makefile,v 1.4 2010/06/13 22:46:57 thomasklausner Exp $
#

DISTNAME=		cairo-java-1.0.1
PKGREVISION=		1
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/cairo-java/1.0/}

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://java-gnome.sourceforge.net/
COMMENT=		Cairo bindings for Java

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake pkg-config
CONFIGURE_ARGS+=	--without-gcj-compile # JAVAC=javac
CPPFLAGS+=		-I${PKG_JAVA_HOME}/include

.include "../../graphics/cairo/buildlink3.mk"
.include "../../wip/glib-java/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../wip/mk/java-app.mk"
.include "../../mk/java-env.mk"
.include "../../mk/bsd.pkg.mk"
