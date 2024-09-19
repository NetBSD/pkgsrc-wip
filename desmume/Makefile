# $NetBSD: Makefile,v 1.16 2015/04/19 15:10:39 othyro Exp $
#

DISTNAME=	desmume-release-0.9.13
PKGREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=desmume2/}
### EXTRACT_SUFX=	.tar.tar
EXTRACT_CMD=	${TAR} xzf $$extract_file

MAINTAINER=	goon.mage@yahoo.com	
HOMEPAGE=	http://desmume2.sourceforge.net/
COMMENT=	Nintendo DS emulator
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake intltool msgfmt msgmerge perl pkg-config tar xgettext

USE_LANGUAGES=	c c++

.include "options.mk"

.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
BUILDLINK_API_DEPENDS.soundtouch+=	soundtouch>=1.5.0
BUILDLINK_DEPMETHOD.soundtouch=	full
.include "../../audio/soundtouch/buildlink3.mk"
.include "../../audio/alsa-lib/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../archivers/zziplib/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../graphics/agg/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtkglext+=	gtkglext>=1.2.0nb4
.include "../../graphics/gtkglext/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
