# $NetBSD: Makefile,v 1.11 2004/04/23 12:01:15 jmmv Exp $
#

DISTNAME=	gnumeric-1.2.8
CATEGORIES=	math gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gnumeric/1.2/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://www.gnome.org/gnumeric/
COMMENT=	Spreadsheet program from the GNOME project

BUILD_USES_MSGFMT=	yes
BUILDLINK_DEPENDS.freetype2=	freetype2>=2.1.4

USE_BUILDLINK3=		YES
USE_DIRS+=		gnome2-1.5
USE_PKGLOCALEDIR=	YES
USE_X11BASE=		YES
USE_GNU_TOOLS+=		make
USE_PERL5=		YES

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--with-python=${PYTHONBIN:T}
CONFIGURE_ARGS+=	--with-bonobo --with-gnome-db
CONFIGURE_ARGS+=	--without-psiconv --without-guile
LIBS+=      		-lunicode

USE_LIBTOOL=		YES

GCONF2_SCHEMAS=		gnumeric-dialogs.schemas
GCONF2_SCHEMAS+=	gnumeric-general.schemas
GCONF2_SCHEMAS+=	gnumeric-plugins.schemas

PKGCONFIG_OVERRIDE=	src/cut-n-paste-code/foocanvas/libfoocanvas/libfoocanvas.pc.in

PYTHON_VERSIONS_ACCEPTED=	23pth

.include "../../lang/python/application.mk"
.include "../../devel/GConf2/schemas.mk"
.include "../../textproc/scrollkeeper/omf.mk"

.include "../../graphics/freetype2/buildlink3.mk"
.include "../../databases/libgnomedb/buildlink3.mk"
.include "../../devel/libgsf/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../devel/libgnome/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../graphics/libart2/buildlink3.mk"
.include "../../graphics/libgnomecanvas/buildlink3.mk"
.include "../../print/libgnomeprint/buildlink3.mk"
.include "../../print/libgnomeprintui/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../textproc/libunicode/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/py-gtk2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
