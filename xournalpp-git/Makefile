# $NetBSD$

DISTNAME=	xournalpp-0.0
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GITHUB:=xournalpp/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/xournalpp/xournalpp/
COMMENT=	Handwriting notetaking software with PDF annotation support
LICENSE=	gnu-gpl-v2

GIT_REPOSITORIES=	xournalpp
#GIT_BRANCH.xournalpp=	master
GIT_REPO.xournalpp=	git://github.com/xournalpp/xournalpp.git
WRKSRC=			${WRKDIR}/xournalpp

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

DEPENDS+=	tex-amsfonts-[0-9]*:../../fonts/tex-amsfonts
DEPENDS+=	tex-amsmath-[0-9]*:../../print/tex-amsmath
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
DEPENDS+=	tex-standalone-[0-9]*:../../print/tex-standalone

.include "../../archivers/libzip/buildlink3.mk"
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../audio/portaudio/buildlink3.mk"
.include "../../print/poppler-glib/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
