# $NetBSD$

GITHUB_PROJECT=	xournalpp
DISTNAME=	1.0.12
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GITHUB:=xournalpp/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/xournalpp/xournalpp/
COMMENT=	Handwriting notetaking software with PDF annotation support
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/xournalpp-1.0.12
USE_CMAKE=	yes
USE_LANGUAGES=	c c++

DEPENDS+=	tex-amsfonts-[0-9]*:../../fonts/tex-amsfonts
DEPENDS+=	tex-amsmath-[0-9]*:../../print/tex-amsmath
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
DEPENDS+=	tex-standalone-[0-9]*:../../print/tex-standalone

.include "../../archivers/libzip/buildlink3.mk"
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../audio/portaudio-devel/buildlink3.mk"
.include "../../print/poppler-glib/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
