# $NetBSD: Makefile,v 1.3 2005/11/02 18:00:20 thomasklausner Exp $
#

DISTNAME=		libglade-java-2.10.1
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/libglade-java/2.10/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://java-gnome.sourceforge.net/
COMMENT=		Glade bindings for Java

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE+=	${WRKSRC}/glade-java.pc.in
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-gcj-compile

.include "../../devel/libglade2/buildlink3.mk"
.include "../../wip/libgnome-java/buildlink3.mk"
.include "../../wip/libgtk-java/buildlink3.mk"
.include "../../wip/mk/java-app.mk"
.include "../../mk/bsd.pkg.mk"
