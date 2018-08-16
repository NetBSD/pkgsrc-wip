# $NetBSD$

DISTNAME=	epix-1.2.18
CATEGORIES=	graphics
MASTER_SITES=	http://math.holycross.edu/~ahwang/epix/

MAINTAINER=	aran@100acres.us
HOMEPAGE=	http://math.holycross.edu/~ahwang/epix/
COMMENT=	Collection of batch utilities that create figures, plots, and movies
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++
USE_TOOLS=      	bash:run ghostscript gmake makeinfo
INFO_FILES=     	yes

BUILD_DEPENDS+=		tex-latex-[0-9]*:../../print/tex-latex
BUILD_DEPENDS+=		tex-latex-bin-[0-9]*:../../print/tex-latex-bin
BUILD_DEPENDS+=		tex-amsmath-[0-9]*:../../print/tex-amsmath
BUILD_DEPENDS+=		tex-eepic-[0-9]*:../../graphics/tex-eepic
BUILD_DEPENDS+=		tex-pstricks-[0-9]*:../../graphics/tex-pstricks
BUILD_DEPENDS+=		tex-xcolor-[0-9]*:../../print/tex-xcolor
BUILD_DEPENDS+=		tex-comment-[0-9]*:../../print/tex-comment
BUILD_DEPENDS+=		tex-iftex-[0-9]*:../../print/tex-iftex
BUILD_DEPENDS+=		tex-pgf-[0-9]*:../../print/tex-pgf
BUILD_DEPENDS+=		tex-geometry-[0-9]*:../../print/tex-geometry
BUILD_DEPENDS+=		tex-index-[0-9]*:../../print/tex-index
BUILD_DEPENDS+=		tex-hyperref-[0-9]*:../../print/tex-hyperref
BUILD_DEPENDS+=		makeindexk-[0-9]*:../../textproc/makeindexk
BUILD_DEPENDS+=		dvipsk-[0-9]*:../../print/dvipsk
BUILD_DEPENDS+=		tex-pst-tools-[0-9]*:../../graphics/tex-pst-tools

REPLACE_BASH+=	elaps.in epix.in flix.in laps.in

SUBST_CLASSES+=		bash
SUBST_SED.bash+=	-e 's,@bashpath@,${BASH},'
SUBST_FILES.bash+=	epix.el.in
SUBST_MESSAGE.bash=	Fixing path to bash.
SUBST_STAGE.bash=	pre-configure

.include "../../mk/bsd.pkg.mk"
