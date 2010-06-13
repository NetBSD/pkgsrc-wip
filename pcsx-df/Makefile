# $NetBSD: Makefile,v 1.2 2010/06/13 22:47:13 thomasklausner Exp $
#

DISTNAME=	pcsx-df-1.10
PKGREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pcsx-df/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pcsx-df.sourceforge.net/
COMMENT=	Playstation 1 emulator optimized for Open Source Unix systems

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		intltool pkg-config

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
