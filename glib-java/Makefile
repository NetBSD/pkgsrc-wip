# $NetBSD: Makefile,v 1.9 2012/12/04 02:37:15 othyro Exp $
#

DISTNAME=	glib-java-0.4.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/glib-java/0.4/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://java-gnome.sourceforge.net/
COMMENT=	Glib bindings for Java
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_LANGUAGES+=		c c++ fortran
USE_TOOLS+=		aclocal autoconf automake gmake gsed pkg-config
CONFIGURE_ARGS+=	--without-gcj-compile

.include "../../devel/glib2/buildlink3.mk"
.include "../../wip/mk/java-app.mk"
.include "../../mk/bsd.pkg.mk"
