# $NetBSD: Makefile,v 1.8 2012/11/25 23:32:26 othyro Exp $
#

DISTNAME=		libgtkhtml-java-2.6.0
PKGREVISION=		3
CATEGORIES=		www
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/libgtkhtml-java/2.6/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://java-gnome.sourceforge.net/
COMMENT=		GtkHtml bindings for Java


USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE+=	${WRKSRC}/gtkhtml-java.pc.in
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake
CONFIGURE_ARGS+=	--without-gcj-compile

.include "../../www/libgtkhtml/buildlink3.mk"
.include "../../wip/libgnome-java/buildlink3.mk"
.include "../../wip/libgtk-java/buildlink3.mk"
.include "../../wip/mk/java-app.mk"
.include "../../mk/bsd.pkg.mk"
