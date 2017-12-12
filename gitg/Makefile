# $NetBSD: Makefile,v 1.4 2013/08/20 11:23:07 shattered Exp $
#

DISTNAME=	gitg-0.2.7
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gitg/0.2/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://trac.novowork.com/gitg/
COMMENT=	Git repository browser
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config intltool gmake msgfmt

GCONF_SCHEMAS+=		data/gitg.schemas
PKGCONFIG_OVERRIDE+=	libgitg-1.0.pc.in
USE_PKGLOCALEDIR=	yes

.include "../../devel/GConf/schemas.mk"
.include "../../graphics/gnome-icon-theme/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/gsettings-desktop-schemas/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../x11/gtksourceview3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
