# $NetBSD: Makefile,v 1.8 2012/09/24 16:56:38 asau Exp $
#

DISTNAME=	apvlv-0.1.5
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_GITHUB:=naihe2010/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://naihe2010.github.io/apvlv/
COMMENT=	PDF/DJVU/UMD/TXT Viewer which behaves like Vim
LICENSE=	gnu-gpl-v2

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

SUBST_CLASSES+=			cmakelists
SUBST_STAGE.cmakelists=		pre-configure
SUBST_MESSAGE.cmakelists=	Fixing CMakeLists.txt
SUBST_FILES.cmakelists=		CMakeLists.txt
SUBST_SED.cmakelists+=		-e 's,share/man,${PKGMANDIR},g'

.include "../../print/poppler-glib/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
