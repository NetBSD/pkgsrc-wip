# $NetBSD$

DISTNAME=	glide-0.5.8
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_GITHUB:=philn/}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/philn/glide/
COMMENT=	Cross-platform media player based on GStreamer and GTK+
LICENSE=	mit

.include "cargo-depends.mk"

USE_LANGUAGES+=			c	# rust, but needs a toolchain to link
USE_TOOLS+=			pkg-config
PYTHON_VERSIONS_ACCEPTED=	37
PYTHON_FOR_BUILD_ONLY=		tool

REPLACE_PYTHON+=	scripts/meson_post_install.py

SUBST_CLASSES+=		prefix
SUBST_MESSAGE.prefix=	Fixing paths.
SUBST_STAGE.prefix=	pre-configure
SUBST_FILES.prefix+=	scripts/meson_post_install.py
SUBST_SED.prefix+=	-e 's,/usr/bin,${PREFIX},g'

INSTALLATION_DIRS=	bin share

.include "../../devel/meson/build.mk"
.include "../../lang/rust/cargo.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../multimedia/gstreamer1/buildlink3.mk"
.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
.include "../../multimedia/gst-plugins1-bad/buildlink3.mk"
.include "../../multimedia/gst-plugins1-good/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/cairo-gobject/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../devel/atk/buildlink3.mk"
.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
