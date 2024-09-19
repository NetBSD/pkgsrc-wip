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
USE_TOOLS=		bash:run ghostscript gmake makeinfo
INFO_FILES=		yes

TOOL_DEPENDS+=		tex-latex-[0-9]*:../../print/tex-latex
TOOL_DEPENDS+=		tex-latex-bin-[0-9]*:../../print/tex-latex-bin
TOOL_DEPENDS+=		tex-amsmath-[0-9]*:../../print/tex-amsmath
TOOL_DEPENDS+=		tex-eepic-[0-9]*:../../graphics/tex-eepic
TOOL_DEPENDS+=		tex-pstricks-[0-9]*:../../graphics/tex-pstricks
TOOL_DEPENDS+=		tex-xcolor-[0-9]*:../../print/tex-xcolor
TOOL_DEPENDS+=		tex-comment-[0-9]*:../../print/tex-comment
TOOL_DEPENDS+=		tex-iftex-[0-9]*:../../print/tex-iftex
TOOL_DEPENDS+=		tex-pgf-[0-9]*:../../print/tex-pgf
TOOL_DEPENDS+=		tex-geometry-[0-9]*:../../print/tex-geometry
TOOL_DEPENDS+=		tex-index-[0-9]*:../../print/tex-index
TOOL_DEPENDS+=		tex-hyperref-[0-9]*:../../print/tex-hyperref
TOOL_DEPENDS+=		makeindexk-[0-9]*:../../textproc/makeindexk
TOOL_DEPENDS+=		dvipsk-[0-9]*:../../print/dvipsk
TOOL_DEPENDS+=		tex-pst-tools-[0-9]*:../../graphics/tex-pst-tools

REPLACE_BASH+=	elaps.in epix.in flix.in laps.in

SUBST_CLASSES+=		bash
SUBST_SED.bash+=	-e 's,@bashpath@,${BASH},'
SUBST_FILES.bash+=	epix.el.in
SUBST_MESSAGE.bash=	Fixing path to bash.
SUBST_STAGE.bash=	pre-configure

.include "../../mk/bsd.pkg.mk"
