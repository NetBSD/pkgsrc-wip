# $NetBSD: Makefile,v 1.15 2007/09/19 23:53:32 thomasklausner Exp $
#

DISTNAME=		metatheme-0.9.7
CATEGORIES=		misc
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/metatheme/0.9/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		recht@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Themes for GNOME 2

USE_TOOLS+=		gmake intltool msgfmt pkg-config
USE_DIRS+=		xdg-1.1
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

.include "../../devel/GConf2/buildlink3.mk"
.include "../../devel/libbonobo/buildlink3.mk"
.include "../../devel/libbonoboui/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../graphics/libgnomecanvas/buildlink3.mk"
.include "../../x11/control-center/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
