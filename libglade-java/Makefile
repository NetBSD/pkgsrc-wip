# $NetBSD: Makefile,v 1.7 2012/11/25 23:32:25 othyro Exp $
#

DISTNAME=		libglade-java-2.10.1
PKGREVISION=		2
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/libglade-java/2.10/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://java-gnome.sourceforge.net/
COMMENT=		Glade bindings for Java


USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE+=	${WRKSRC}/glade-java.pc.in
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-gcj-compile

.include "../../devel/libglade/buildlink3.mk"
.include "../../wip/libgnome-java/buildlink3.mk"
.include "../../wip/libgtk-java/buildlink3.mk"
.include "../../wip/mk/java-app.mk"
.include "../../mk/bsd.pkg.mk"
