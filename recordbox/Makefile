# $NetBSD$

DISTNAME=	Recordbox-v0.11.0-beta.1
PKGNAME=	${DISTNAME:S,-v,-,:S/-beta./beta/:S/R/r/}
CATEGORIES=	audio
# automatic download doesn't work, please fetch manually
#MASTER_SITES=	https://codeberg.org/edestcroix/Recordbox/archive/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://codeberg.org/edestcroix/Recordbox/
COMMENT=	Relatively simple music player
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}/recordbox

USE_TOOLS+=	pkg-config

.include "cargo-depends.mk"

.include "../../devel/meson/build.mk"
.include "../../lang/rust/cargo.mk"
.include "../../databases/sqlite3/buildlink3.mk"
BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.66
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libadwaita/buildlink3.mk"
.include "../../graphics/lcms2/buildlink3.mk"
# libseccomp?
.include "../../multimedia/gstreamer1/buildlink3.mk"
.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
.include "../../multimedia/gst-plugins1-bad/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../x11/gtk4/buildlink3.mk"
.include "../../devel/gettext-tools/msgfmt-desktop.mk"
.include "../../mk/bsd.pkg.mk"
