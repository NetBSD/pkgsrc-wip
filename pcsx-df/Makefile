# $NetBSD: Makefile,v 1.5 2012/10/05 08:46:09 asau Exp $
#

DISTNAME=	pcsx-df-1.10
PKGREVISION=	2
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pcsx-df/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pcsx-df.sourceforge.net/
COMMENT=	Playstation 1 emulator optimized for Open Source Unix systems
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++ fortran
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		intltool pkg-config

SUBST_CLASSES+=		datadir
SUBST_STAGE.datadir=	post-configure
SUBST_MESSAGE.datadir=	Fixing hardcoded PACKAGE_DATA_DIR path
SUBST_FILES.datadir=	gui/Config.c
SUBST_SED.datadir=	-e 's,/usr/lib/games/psemu/,${PREFIX}/lib/games/psemu/,'

# obsolete
CONFIGURE_ARGS+=	--disable-nautilusburn

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../audio/alsa-lib/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libXv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
