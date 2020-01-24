# $NetBSD: Makefile,v 1.7 2012/11/25 23:32:09 othyro Exp $
#

DISTNAME=		cairo-java-1.0.1
PKGREVISION=		1
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/cairo-java/1.0/}
LICENSE=		gnu-gpl-v2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://java-gnome.sourceforge.net/
COMMENT=		Cairo bindings for Java

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake pkg-config
CONFIGURE_ARGS+=	--without-gcj-compile # JAVAC=javac
CPPFLAGS+=		-I${PKG_JAVA_HOME}/include

.include "../../graphics/cairo/buildlink3.mk"
.include "../../wip/glib-java/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../wip/mk/java-app.mk"
.include "../../mk/java-env.mk"
.include "../../mk/bsd.pkg.mk"
