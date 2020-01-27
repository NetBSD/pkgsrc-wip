# $NetBSD$

PKGNAME=	edb-debugger-0.9.21
CATEGORIES=	devel

GIT_REPOSITORIES=	edb
GIT_REPO.edb=		git://github.com/eteran/edb-debugger.git

WRKSRC=		${WRKDIR}/edb

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://codef00.com/projects#debugger
COMMENT=	Cross platform x86/x86-64 debugger
LICENSE=	gnu-gpl-v2

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

.include "../../x11/qt5-qtsvg/buildlink3.mk"
.include "../../wip/mk/git-package.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../graphics/graphviz/buildlink3.mk"
.include "../../x11/qt5-qtxmlpatterns/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../devel/capstone/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
