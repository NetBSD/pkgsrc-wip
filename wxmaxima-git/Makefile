# $NetBSD: Makefile,v 1.4 2017/02/12 06:25:43 ryoon Exp $

DISTNAME=	wxmaxima-17.05.1
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GITHUB:=andrejv/}
GITHUB_TAG=	Version-${PKGVERSION_NOREV}

MAINTAINER=	helgoman@users.sourceforge.net
HOMEPAGE=	http://andrejv.github.io/wxmaxima/
COMMENT=	Graphical UI for maxima
LICENSE=	gnu-gpl-v2

GIT_REPOSITORIES=	wxmaxima
GIT_REPO.wxmaxima=	git://github.com/andrejv/wxmaxima.git
WRKSRC=		${WRKDIR}/wxmaxima

DEPENDS+=	maxima>=5.15.0:../../math/maxima
DEPENDS+=	gnuplot>=4.2.3:../../graphics/gnuplot

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

NOT_PAX_MPROTECT_SAFE=	bin/wxmaxima

SUBST_CLASSES+=		man
SUBST_FILES.man=	data/CMakeLists.txt
SUBST_STAGE.man=	pre-configure
SUBST_SED.man+=		-e "s,share/man,${PKGMANDIR},g"
SUBST_MESSAGE.man=	Fixing man page installation path.

.include "../../x11/wxGTK30/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
