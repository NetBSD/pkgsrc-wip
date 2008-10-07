# $NetBSD: Makefile,v 1.2 2008/10/07 19:45:06 tonnerre Exp $
#

DISTNAME=	midori-0.0.21
CATEGORIES=	www
MASTER_SITES=	http://goodies.xfce.org/releases/midori/

MAINTAINER=	ahoka@NetBSD.org
HOMEPAGE=	http://www.twotoasts.de/media/midori/
COMMENT=	Lightweight web browser using WebKit
EXTRACT_SUFX=	.tar.bz2

HAS_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_DIRS+=	xdg-1.4
CONFIGURE_FLAGS+=	--prefix=${PREFIX:Q}

USE_TOOLS+=	intltool pkg-config msgfmt gmake

.include "../../x11/gtk2/buildlink3.mk"
.include "../../devel/libsexy/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../wip/webkit-gtk/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
