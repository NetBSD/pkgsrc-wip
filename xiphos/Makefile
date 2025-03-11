# $NetBSD$

DISTNAME=	xiphos-4.2.1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=crosswire/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	ktnb@NetBSD.org
HOMEPAGE=	https://github.com/crosswire/xiphos/
COMMENT=	Bible study tool utilizing the sword framework
LICENSE=	gnu-gpl-v2

USE_PKGLOCALEDIR=	yes
USE_CXX_FEATURES+=	c++17
FORCE_CXX_STD+=		c++17
USE_LANGUAGES=		c c++

USE_TOOLS+=	pkg-config itstool intltool gettext-tools

CMAKE_ARGS+=	-DEPUB=OFF
CMAKE_ARGS+=	-DGTKHTML=ON

.include "../../archivers/minizip/buildlink3.mk"
.include "../../devel/appstream-glib/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../devel/libuuid/buildlink3.mk"
.include "../../devel/libgsf/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../net/libsoup/buildlink3.mk"
.include "../../misc/sword/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../textproc/enchant2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../wip/biblesync/buildlink3.mk"
.include "../../www/webkit-gtk/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
