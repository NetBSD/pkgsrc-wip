# $NetBSD$

DISTNAME=	svg
PKGNAME=	tex-${DISTNAME}-2.02k
TEXLIVE_REV=	70626

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/svg
COMMENT=	Include and extract SVG pictures in LaTeX documents
LICENSE=	lppl-1.3c

DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-iftex-[0-9]*:../../print/tex-iftex
DEPENDS+=	tex-koma-script-[0-9]*:../../print/tex-koma-script
DEPENDS+=	tex-pdftexcmds-[0-9]*:../../print/tex-pdftexcmds
DEPENDS+=	tex-tools-[0-9]*:../../print/tex-tools
DEPENDS+=	tex-trimspaces-[0-9]*:../../print/tex-trimspaces
DEPENDS+=	tex-transparent-[0-9]*:../../print/tex-transparent
DEPENDS+=	tex-ifplatform-[0-9]*:../../print/tex-ifplatform
DEPENDS+=	tex-l3experimental-[0-9]*:../../devel/tex-l3experimental
DEPENDS+=	inkscape-[0-9]*:../../graphics/inkscape

# catalogue-contact-bugs https://github.com/mrpiggi/svg/issues
# catalogue-contact-repository https://github.com/mrpiggi/svg

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
