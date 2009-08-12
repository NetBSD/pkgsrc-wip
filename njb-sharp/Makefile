# $NetBSD: Makefile,v 1.4 2009/08/12 02:32:05 obache Exp $
#

DISTNAME=	njb-sharp-0.3.0
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://download.banshee-project.org/legacy/njb-sharp/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://download.banshee-project.org/legacy/njb-sharp/
COMMENT=	Mono C\# Bindings to libnjb
#LICENSE=	LICENSE

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

BUILDLINK_API_DEPENDS.libnjb+=	libnjb>=2.2.6

CONFIGURE_ARGS+=	--disable-monodoc

PKGCONFIG_OVERRIDE+=	njb-sharp.pc.in

.include "../../lang/mono/buildlink3.mk"
.include "../../wip/libnjb/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
