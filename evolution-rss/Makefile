# $NetBSD: Makefile,v 1.7 2015/06/07 14:24:48 yrmt Exp $
#

DISTNAME=	evolution-rss-0.2.1
CATEGORIES=	mail gnome
MASTER_SITES=	http://gnome.eu.org/

MAINTAINER=	pkgsrc.gnome@gmail.com
HOMEPAGE=	http://gnome.eu.org/evo/index.php/Evolution_RSS_Reader_Plugin
COMMENT=	Evolution rss reader plugin
LICENSE=	gnu-gpl-v2

DEPENDS+=	gsed>=:../../textproc/gsed

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config intltool  gmake msgfmt
USE_LANGUAGES=	c c++

CFLAGS+=	-DGTK_COMPILATION

GCONF_SCHEMAS+=	evolution-rss.schemas

GSED=			${PREFIX}/bin/gsed

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_SED.paths+=	-e 's|@GSED@|${GSED}|g'
SUBST_FILES.paths+=	src/Makefile.in
SUBST_MESSAGE.paths=	Fixing gsed path.

post-extract:
	ln -s ${WRKSRC}/src/evolution-rss.schemas ${WRKSRC}

.include "options.mk"

.include "../../devel/GConf/schemas.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mail/evolution/buildlink3.mk"
.include "../../net/libsoup/buildlink3.mk"
#.include "../../textproc/libxml2/buildlink3.mk"
BUILDLINK_API_DEPENDS.libgtkhtml+=		libgtkhtml>=2.6.0
.include "../../www/gtkhtml314/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
