# $NetBSD: Makefile,v 1.5 2012/10/03 21:32:46 asau Exp $
#

DISTNAME=		ogmrip-0.13.7
#PKGREVISION=		2
CATEGORIES=		multimedia
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=ogmrip/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ogmrip.sourceforge.net/
COMMENT=	Application for ripping and encoding DVD into DivX/OGM files
LICENSE=	gnu-lgpl-v2.1

DEPENDS+=		mencoder-[0-9]*:../../multimedia/mencoder
DEPENDS+=		mkvtoolnix-[0-9]*:../../multimedia/mkvtoolnix
DEPENDS+=		mplayer-[0-9]*:../../multimedia/mplayer
DEPENDS+=		ogmtools-[0-9]*:../../multimedia/ogmtools
DEPENDS+=		vorbis-tools-[0-9]*:../../audio/vorbis-tools
DEPENDS+=		gocr-[0-9]*:../../graphics/gocr
BUILD_DEPENDS+=		gtk-doc-[0-9]*:../../textproc/gtk-doc
BUILD_DEPENDS+=		gsed-[0-9]*:../../textproc/gsed

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	SED_PROG=${LOCALBASE}/bin/gsed

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake intltool pkg-config gsed
PKGCONFIG_OVERRIDE+=	${WRKSRC}/data/ogmdvd.pc.in
PKGCONFIG_OVERRIDE+=	${WRKSRC}/data/ogmrip.pc.in

GCONF_SCHEMAS+=		ogmrip.schemas

BUILDLINK_TRANSFORM+=	rm:-Werror

.include "../../devel/GConf/schemas.mk"

.include "../../audio/faac/buildlink3.mk"
.include "../../audio/lame/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
#.include "../../devel/libgnome/buildlink3.mk"
#.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../multimedia/gpac/buildlink3.mk"
.include "../../multimedia/libdvdread/buildlink3.mk"
.include "../../multimedia/libtheora/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/hal/buildlink3.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
# subtitle spell checking
.include "../../textproc/enchant/buildlink3.mk"
.include "../../textproc/enca/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
