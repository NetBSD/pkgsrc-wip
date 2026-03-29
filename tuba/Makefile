# $NetBSD$

DISTNAME=	Tuba-0.10.3
PKGNAME=	${DISTNAME:tl}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=GeopJr/}
GITHUB_PROJECT=	Tuba
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/GeopJr/Tuba/
COMMENT=	Mastodon browser
LICENSE=	gnu-gpl-v3

DEPENDS+=	gnome-keyring-[0-9]*:../../security/gnome-keyring
DEPENDS+=	webp-pixbuf-loader-[0-9]*:../../graphics/webp-pixbuf-loader

USE_TOOLS+=	pkg-config

MESON_ARGS+=	-Dclapper=disabled

.include "../../devel/meson/build.mk"
.include "../../devel/glib2/schemas.mk"
BUILDLINK_API_DEPENDS.libadwaita+=	libadwaita>=1.8
.include "../../devel/libadwaita/buildlink3.mk"
.include "../../devel/libgee/buildlink3.mk"
.include "../../graphics/gexiv2/buildlink3.mk"
.include "../../graphics/libwebp/buildlink3.mk"
.include "../../lang/vala/buildlink3.mk"
.include "../../multimedia/gstreamer1/buildlink3.mk"
.include "../../net/libsoup3/buildlink3.mk"
.include "../../security/libsecret/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
#.include "../../textproc/libspelling/buildlink3.mk"
.include "../../textproc/json-glib/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../x11/gtksourceview5/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
