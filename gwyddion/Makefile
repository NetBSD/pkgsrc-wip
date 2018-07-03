# $NetBSD: Makefile,v 1.5 2014/05/09 07:38:43 thomasklausner Exp $

DISTNAME=	gwyddion-2.20
CATEGORIES=	graphics #science
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gwyddion/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://gwyddion.sourceforge.net/
COMMENT=	Gtk2 based SPM data visualization and analysis tool
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		PYTHON=${PYTHONBIN}
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config intltool msgfmt gmake perl
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++

GCONF_SCHEMAS+=		data/gwyddion-thumbnailer.schemas
PKGCONFIG_OVERRIDE+=	data/gwyddion.pc.in

SUBST_CLASSES+=		schema
SUBST_STAGE.schema=	pre-configure
SUBST_MESSAGE.schema=	Fixing schema installation path.
SUBST_FILES.schema+=	data/Makefile.in
SUBST_SED.schema+=	-e "s,..sysconfdir./gconf/schemas,${PREFIX}/share/gconf/schemas/,"

PKG_OPTIONS_VAR=		PKG_OPTIONS.gwyddion
PKG_SUPPORTED_OPTIONS=		pygwy fftw3
PKG_SUGGESTED_OPTIONS=		pygwy fftw3

.include "../../mk/bsd.options.mk"

.if !empty (PKG_OPTIONS:Mpygwy)
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # py-gtk2
.include "../../x11/py-gtk2/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-pygwy
.endif

.if !empty (PKG_OPTIONS:Mfftw3)
BUILDLINK_API_DEPENDS.fftw+=	fftw>=3.0
.include "../../math/fftw/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-fftw3
.endif

.include "../../databases/shared-mime-info/buildlink3.mk"
.include "../../devel/GConf/schemas.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/gtkglext/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/ruby/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
BUILDLINK_API_DEPENDS.libxml2+=	libxml2>=2.6.2
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtk2+=	gtk2+>=2.4.0
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/gtksourceview2/buildlink3.mk"
.include "../../x11/libunique/buildlink3.mk"
.include "../../mk/omf-scrollkeeper.mk"
.include "../../mk/bsd.pkg.mk"
