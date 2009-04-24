# $NetBSD: Makefile,v 1.1.1.1 2009/04/24 23:48:46 jihbed Exp $
#

DISTNAME=	njb-sharp-0.2.2
CATEGORIES=	audio
MASTER_SITES=	http://download.banshee-project.org/njb-sharp/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://download.banshee-project.org/njb-sharp/
COMMENT=	Sharp binding for libnjb

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

PKG_DESTDIR_SUPPORT=	user-destdir

PKGCONFIG_OVERRIDE+=	njb-sharp.pc.in

CONFIGURE_ARGS+=	--disable-monodoc

.include "../../lang/mono/buildlink3.mk"
BUILDLINK_API_DEPENDS.libnjb+=	libnjb>=2.2.6
.include "../../wip/libnjb/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
