# $NetBSD$

DISTNAME=	edbrowse-3.7.5.1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=CMB/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://edbrowse.org/
COMMENT=	Command Line Editor Browser
LICENSE=	gnu-gpl-v3

USE_CMAKE=	yes
USE_TOOLS+=	perl:build
USE_LANGUAGES=	c c++

CMAKE_ARGS+=	-DTIDY_ROOT=${PREFIX}/include/tidy

SUBST_CLASSES+=		man
SUBST_STAGE.man=	pre-patch
SUBST_MESSAGE.man=	Fixing paths in man page
SUBST_FILES.man=	doc/man-edbrowse-debian.1
SUBST_SED.man=		-e '/usersguide\.html/ s,/usr,${PREFIX},g'

SUBST_CLASSES+=			cmakelists
SUBST_STAGE.cmakelists=		post-patch
SUBST_MESSAGE.cmakelists=	Fixing paths in CMakeLists.txt
SUBST_FILES.cmakelists=		CMakeLists.txt
SUBST_VARS.cmakelists=		PREFIX PKGMANDIR

.include "../../devel/pcre/buildlink3.mk"
BUILDLINK_API_DEPENDS.libduktape+=	libduktape>=2.1.0
.include "../../lang/libduktape/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../www/tidy/buildlink3.mk"
.include "../../mk/readline.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
