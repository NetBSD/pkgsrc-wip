# $NetBSD$

GITHUB_PROJECT=	navit
DISTNAME=	v0.5.1
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
PKGREVISION=    1
CATEGORIES=	geography
MASTER_SITES=	${MASTER_SITE_GITHUB:=navit-gps/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	fekete.zoltan@minux.hu
HOMEPAGE=	https://github.com/navit-gps/navit/
COMMENT=	GPS car navigation system
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/navit-0.5.1
USE_CMAKE=	yes
USE_LANGUAGES=	c c++

#USE_LIBTOOL=		yes
#USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		cmake gettext

# LIBS.Linux+= -ldl

DEPENDS+=       png>=1.6:../../graphics/png
DEPENDS+=       freetype2>=2.9:../../graphics/freetype2
DEPENDS+=       glib2>=2.0:../../devel/glib2
DEPENDS+=       python27-[0-9]*:../../lang/python27
DEPENDS+=       gtk2-[0-9]*:../../x11/gtk2

BUILD_DEPENDS+=gettext-lib-[0-9]*:../../devel/gettext-lib

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../lang/python27/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
BUILDLINK_TRANSFORM+=opt:-ldl:${BUILDLINK_LDADD.dl:M*}
.include "../../mk/bsd.pkg.mk"
