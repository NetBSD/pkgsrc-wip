# $NetBSD: Makefile,v 1.4 2005/05/31 00:13:41 thomasklausner Exp $
#

DISTNAME=	planner-0.12.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/planner/0.12/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc@blackmouse.biz
HOMEPAGE=	http://www.imendio.com/projects/planner/
COMMENT=	GTK2 project management tool

BUILD_DEPENDS=		p5-XML-Parser>=2.31nb1:../../textproc/p5-XML-Parser
BUILD_USES_MSGFMT=	yes

USE_DIRS+=		gnome2-1.5
USE_TOOLS+=		gmake
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--enable-python
CONFIGURE_ARGS+=	--enable-python-plugin
CONFIGURE_ARGS+=	--enable-timetable
CONFIGURE_ARGS+=	--disable-dotnet
CONFIGURE_ARGS+=	--enable-database=yes

.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../databases/libgda/buildlink3.mk"
.include "../../devel/libgsf/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/libbonoboui/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../print/libgnomeprintui/buildlink3.mk"
.include "../../sysutils/gnome-vfs2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../databases/shared-mime-info/mimedb.mk"
.include "../../mk/bsd.pkg.mk"
