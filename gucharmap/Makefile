# $NetBSD$
#

DISTNAME=	gucharmap-10.0.0
CATEGORIES=	fonts gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gucharmap/10.0/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://live.gnome.org/Gucharmap
COMMENT=	Unicode/ISO10646 character map and font viewer
LICENSE=	gnu-gpl-v3 AND unicode

DIST_SUBDIR=	${DISTNAME}

EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

UNICODE_DISTFILES= \
	Blocks.txt \
	DerivedAge.txt \
        NamesList.txt \
        Scripts.txt \
        UnicodeData.txt \
        Unihan.zip

.for ud in ${UNICODE_DISTFILES}
DISTFILES+=		${ud}
SITES.${ud}=		http://www.unicode.org/Public/10.0.0/ucd/
.endfor

CONFIGURE_ARGS+=	--with-unicode-data=${DISTDIR}/${DIST_SUBDIR}

USE_TOOLS+=		gmake intltool msgfmt pkg-config
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

#PKGCONFIG_OVERRIDE+=	gucharmap-2.pc.in

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/schemas.mk"
BUILDLINK_API_DEPENDS.glib2+=		glib2>=2.32.0
.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../mk/omf-scrollkeeper.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
BUILDLINK_API_DEPENDS.gtk3+=		gtk3+>=3.4.0
.include "../../x11/gtk3/modules.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
