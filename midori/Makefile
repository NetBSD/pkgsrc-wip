# $NetBSD: Makefile,v 1.1.1.1 2008/07/23 11:02:32 hoka_adam Exp $
#

DISTNAME=	midori-0.0.18
CATEGORIES=	www
MASTER_SITES=	http://www.twotoasts.de/media/midori/

MAINTAINER=	ahoka@NetBSD.org
HOMEPAGE=	http://www.twotoasts.de/media/midori/
COMMENT=	Lightweight web browser using WebKit

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_DIRS+=	xdg-1.4

USE_TOOLS+=	intltool pkg-config msgfmt gmake

.include "../../x11/gtk2/buildlink3.mk"
.include "../../devel/libsexy/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../wip/webkit-gtk/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
