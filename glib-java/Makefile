# $NetBSD: Makefile,v 1.5 2009/10/08 22:31:01 thomasklausner Exp $
#

DISTNAME=		glib-java-0.2.5
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/glib-java/0.2/}

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://java-gnome.sourceforge.net/
COMMENT=		Glib bindings for Java

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_LANGUAGES+=		c
USE_TOOLS+=		gmake pkg-config
CONFIGURE_ARGS+=	--without-gcj-compile
CONFIGURE_ARGS+=	JAVAC=${JAVA_BINPREFIX}-javac
CONFIGURE_ARGS+=	JAVADOC=${JAVA_BINPREFIX}-javadoc
CONFIGURE_ARGS+=	JAR=${JAVA_BINPREFIX}-jar
CONFIGURE_ARGS+=	JAVAH=${JAVA_BINPREFIX}-javah
CPPFLAGS+=		-I${PKG_JAVA_HOME}/include

.include "../../devel/glib2/buildlink3.mk"
.include "../../wip/mk/java-app.mk"
.include "../../mk/bsd.pkg.mk"
