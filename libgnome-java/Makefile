# $NetBSD: Makefile,v 1.1.1.1 2005/05/03 16:52:49 poppnk Exp $
#

DISTNAME=		libgnome-java-2.10.1
CATEGORIES=		wip devel
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/libgnome-java/2.10/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://java-gnome.sourceforge.net/
COMMENT=		Gnome bindings for Java

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE+=	${WRKSRC}/gnome2-java.pc.in
GNU_CONFIGURE=		yes
USE_GNU_TOOLS+=		make
CONFIGURE_ARGS+=	--without-gcj-compile

.include "../../devel/libgnome/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../wip/libgtk-java/buildlink3.mk"
.include "../../wip/mk/java-app.mk"
.include "../../mk/bsd.pkg.mk"
