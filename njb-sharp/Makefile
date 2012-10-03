# $NetBSD: Makefile,v 1.6 2012/10/03 18:15:32 asau Exp $
#

DISTNAME=	njb-sharp-0.3.0
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://download.banshee-project.org/legacy/njb-sharp/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://download.banshee-project.org/legacy/njb-sharp/
COMMENT=	Mono C\# Bindings to libnjb
#LICENSE=	LICENSE

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

BUILDLINK_API_DEPENDS.libnjb+=	libnjb>=2.2.6

CONFIGURE_ARGS+=	--disable-monodoc

PKGCONFIG_OVERRIDE+=	njb-sharp.pc.in

.include "../../devel/libnjb/buildlink3.mk"
.include "../../lang/mono/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
