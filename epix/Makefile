# $NetBSD$
#

DISTNAME=	epix-1.2.18
CATEGORIES=	graphics
MASTER_SITES=	http://math.holycross.edu/~ahwang/epix/

MAINTAINER=	aran@100acres.us
HOMEPAGE=	http://math.holycross.edu/~ahwang/epix/
COMMENT=	Collection of batch utilities that create figures, plots, and movies

GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++
USE_TOOLS=      	gmake
INFO_FILES=     	yes

BUILD_DEPENDS+=		tex-latex-[0-9]*:../../print/tex-latex
BUILD_DEPENDS+=		tex-latex-bin-[0-9]*:../../print/tex-latex-bin
BUILD_DEPENDS+=		tex-amsmath-[0-9]*:../../print/tex-amsmath
BUILD_DEPENDS+=		tex-eepic-[0-9]*:../../graphics/tex-eepic
BUILD_DEPENDS+=		tex-pstricks-[0-9]*:../../graphics/tex-pstricks
BUILD_DEPENDS+=		tex-xcolor-[0-9]*:../../print/tex-xcolor
BUILD_DEPENDS+=		tex-comment-[0-9]*:../../graphics/tex-comment

.include "../../mk/bsd.pkg.mk"
