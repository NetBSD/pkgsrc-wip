# $NetBSD: Makefile,v 1.14 2006/10/29 08:32:53 shattered Exp $
#

DISTNAME=		planner-0.14


CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/planner/0.14/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc@blackmouse.biz
HOMEPAGE=		http://live.gnome.org/Planner
COMMENT=		GTK2 project management tool

BUILD_DEPENDS=		p5-XML-Parser>=2.31nb1:../../textproc/p5-XML-Parser

USE_DIRS+=		gnome2-1.5
USE_TOOLS+=		gmake intltool msgfmt pkg-config
USE_LANGUAGES=		c c++

USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
PKGCONFIG_OVERRIDE+=	libplanner-1.pc.in
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--enable-python
CONFIGURE_ARGS+=	--enable-python-plugin
CONFIGURE_ARGS+=	--enable-gtk-doc
CONFIGURE_ARGS+=	--enable-database=no	# this was still not correct (in code, not only in configure)

CONFIGURE_ENV+=		GCONF_SCHEMA_FILE_DIR="${PREFIX}/share/gconf/schemas/"
MAKE_ENV+=		GCONF_SCHEMA_FILE_DIR="${PREFIX}/share/gconf/schemas/"

GCONF2_SCHEMAS+=	planner.schemas

PLIST_SUBST+=	PYSITELIB=${PYSITELIB:Q}

#.include "../../databases/libgda/buildlink3.mk"
.include "../../databases/shared-mime-info/mimedb.mk"
.include "../../devel/GConf2/schemas.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libbonoboui/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/libgsf/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../print/libgnomeprintui/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/gnome-vfs2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../textproc/gtk-doc/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
