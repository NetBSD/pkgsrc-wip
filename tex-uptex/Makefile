# $NetBSD$

DISTNAME=	uptex
PKGNAME=	tex-${DISTNAME}-2020
TEXLIVE_REV=	56291

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/uptex
COMMENT=	Unicode version of pTeX

DEPENDS+=	tex-cm-[0-9]*:../../fonts/tex-cm
DEPENDS+=	tex-etex-[0-9]*:../../print/tex-etex
DEPENDS+=	tex-hyphen-base-[0-9]*:../../print/tex-hyphen-base
DEPENDS+=	tex-knuth-lib-[0-9]*:../../fonts/tex-knuth-lib
DEPENDS+=	tex-plain-[0-9]*:../../print/tex-plain
DEPENDS+=	tex-ptex-base-[0-9]*:../../print/tex-ptex-base
DEPENDS+=	tex-uptex-base-[0-9]*:../../wip/tex-uptex-base
DEPENDS+=	tex-uptex-fonts-[0-9]*:../../wip/tex-uptex-fonts
DEPENDS+=	upmendex-[0-9]*:../../wip/upmendex
DEPENDS+=	web2c>=2020:../../print/web2c

TEX_FORMATS+=	"uptex uptex - uptex.ini\\neuptex euptex language.def *euptex.ini\\n"

TEX_KANJIMAP_FILES+=	uptex-@jaEmbed@@jaVariant@.map
TEX_KANJIMAP_FILES+=	uptex-ko-@koEmbed@.map
TEX_KANJIMAP_FILES+=	uptex-sc-@scEmbed@.map
TEX_KANJIMAP_FILES+=	uptex-tc-@tcEmbed@.map

META_PACKAGE=	yes
TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"

.include "../../mk/bsd.pkg.mk"
