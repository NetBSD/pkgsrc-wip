# $NetBSD: Makefile,v 1.2 2009/04/27 23:36:40 jihbed Exp $
#

DISTNAME=	njb-sharp-0.3.0
CATEGORIES=	audio
MASTER_SITES=	http://download.banshee-project.org/njb-sharp/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://download.banshee-project.org/njb-sharp/
COMMENT=	Sharp binding for libnjb

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
