# $NetBSD: Makefile,v 1.2 2012/09/29 00:50:35 asau Exp $
#

DISTNAME=	gitg-0.0.8
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gitg/0.0/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	shattered@NetBSD.org
HOMEPAGE=	http://trac.novowork.com/gitg/
COMMENT=	Git repository browser
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config intltool gmake msgfmt

GCONF_SCHEMAS+=		data/gitg.schemas
PKGCONFIG_OVERRIDE+=	libgitg-1.0.pc.in
USE_PKGLOCALEDIR=	yes

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../devel/GConf/schemas.mk"
.include "../../graphics/gnome-icon-theme/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/gtksourceview2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
