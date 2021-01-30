# $NetBSD$

DISTNAME=	ptex
PKGNAME=	tex-${DISTNAME}-2020
TEXLIVE_REV=	55920

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/ptex
COMMENT=	TeX system for publishing in Japanese
LICENSE=	modified-bsd

DEPENDS+=	makejvf-[0-9]*:../../wip/makejvf
DEPENDS+=	mendexk-[0-9]*:../../wip/mendexk
DEPENDS+=	tex-cm-[0-9]*:../../fonts/tex-cm
DEPENDS+=	tex-etex-[0-9]*:../../print/tex-etex
DEPENDS+=	tex-hyphen-base-[0-9]*:../../print/tex-hyphen-base
DEPENDS+=	tex-knuth-lib-[0-9]*:../../fonts/tex-knuth-lib
DEPENDS+=	tex-plain-[0-9]*:../../print/tex-plain
DEPENDS+=	tex-ptex-base-[0-9]*:../../print/tex-ptex-base
DEPENDS+=	tex-ptex-fonts-[0-9]*:../../fonts/tex-ptex-fonts
DEPENDS+=	web2c>=2020:../../print/web2c

TEX_FORMATS+=		"ptex ptex - ptex.ini\\neptex eptex language.def *eptex.ini\\n"
TEX_KANJIMAP_FILES+=	ptex-@jaEmbed@@jaVariant@.map

TEXLIVE_UNVERSIONED=   yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
