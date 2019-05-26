# $NetBSD$

DISTNAME=	epiphany-3.30.2
CATEGORIES=	www gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/epiphany/3.30/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gnome.org/projects/epiphany/
COMMENT=	The web browser for the GNOME Desktop
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=	itstool-[0-9]*:../../textproc/itstool

USE_TOOLS+=	pkg-config

LDFLAGS+=	-L${PREFIX}/lib/epiphany ${COMPILER_RPATH_FLAG}${PREFIX}/lib/epiphany

REPLACE_PYTHON+=		post_install.py
PYTHON_VERSIONS_INCOMPATIBLE=	27	# needs Python 3
PYTHON_FOR_BUILD_ONLY=		yes

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/glib2/schemas.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../devel/py-meson/build.mk"
.include "../../lang/python/application.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../security/gcr/buildlink3.mk"
.include "../../security/libsecret/buildlink3.mk"
.include "../../security/nettle/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../textproc/iso-codes/buildlink3.mk"
.include "../../textproc/json-glib/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../www/webkit-gtk/buildlink3.mk"
.include "../../wip/libdazzle/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
