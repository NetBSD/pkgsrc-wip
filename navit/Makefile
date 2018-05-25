# $NetBSD$

DISTNAME=	navit-0.5.1
CATEGORIES=	geography
MASTER_SITES=	${MASTER_SITE_GITHUB:=navit-gps/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	fekete.zoltan@minux.hu
HOMEPAGE=	https://github.com/navit-gps/navit/
COMMENT=	GPS car navigation system
LICENSE=	gnu-gpl-v2

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

#USE_LIBTOOL=		yes
#USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		cmake gettext

# LIBS.Linux+= -ldl

BUILD_DEPENDS+=gettext-lib-[0-9]*:../../devel/gettext-lib

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
BUILDLINK_API_DEPENDS.png+=	png>=1.6
.include "../../graphics/png/buildlink3.mk"
.include "../../lang/python27/buildlink3.mk"
BUILDLINK_API_DEPENDS.freetype2+=	freetype2>=2.9
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.0
.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
BUILDLINK_TRANSFORM+=opt:-ldl:${BUILDLINK_LDADD.dl:M*}
.include "../../mk/bsd.pkg.mk"
