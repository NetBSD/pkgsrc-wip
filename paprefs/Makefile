# $NetBSD: Makefile,v 1.91 2024/04/07 07:33:33 wiz Exp $

DISTNAME=	paprefs-1.2
CATEGORIES=	audio
MASTER_SITES=	http://freedesktop.org/software/pulseaudio/paprefs/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://freedesktop.org/software/pulseaudio/paprefs/
COMMENT=	Configuration dialog for the PulseAudio sound server
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=		c c++
USE_CXX_FEATURES+=	c++11

USE_TOOLS+=	pkg-config # intltool perl msgfmt

.include "../../audio/pulseaudio/buildlink3.mk"
.include "../../devel/gettext-tools/msgfmt-desktop.mk"
.include "../../devel/meson/build.mk"
.include "../../devel/glib2/schemas.mk"
#.include "../../converters/libiconv/buildlink3.mk"
#.include "../../devel/gconfmm/buildlink3.mk"
#.include "../../devel/libglademm/buildlink3.mk"
#.include "../../devel/libsigc++/buildlink3.mk"
#.include "../../sysutils/desktop-file-utils/desktopdb.mk"
#.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/gtkmm3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
