# $NetBSD: Makefile,v 1.1 2015/02/19 21:21:12 jihbed Exp $

DISTNAME=	xapps-1.8.9
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=linuxmint/}
GITHUB_PROJECT=	xapps
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	youri@NetBSD.org
HOMEPAGE=	https://github.com/linuxmint/xapps
COMMENT=	Components which are common to multiple desktop environments
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2


USE_TOOLS=		pkg-config intltool
USE_CMAKE=		yes
USE_LANGUAGES=		c c++ fortran
WRKSRC=			${WRKDIR}/xapp-1.8.9
USE_PKGLOCALEDIR=	yes

PLIST_SUBST+=		PYSITELIB=${PYSITELIB}

.include "../../devel/meson/build.mk"
.include "../../devel/libdbusmenu-gtk3/buildlink3.mk"
.include "../../devel/glib2/schemas.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../devel/py-gobject3-common/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/vala/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../x11/libxklavier/buildlink3.mk"
.include "../../x11/libgnomekbd/buildlink3.mk"
.include "../../x11/libxkbfile/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
