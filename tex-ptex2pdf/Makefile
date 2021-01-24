# $NetBSD$

DISTNAME=	ptex2pdf
PKGNAME=	tex-${DISTNAME}-20200520.0
TEXLIVE_REV=	55219

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/ptex2pdf
COMMENT=	Convert Japanese TeX documents to PDF
LICENSE=	gnu-gpl-v2

INSTALLATION_DIRS+=	bin

SUBST_CLASSES+=		shebang
SUBST_STAGE.shebang=	pre-configure
SUBST_MESSAGE.shebang=	Fixing shebang.
SUBST_FILES.shebang=	texmf-dist/scripts/ptex2pdf/ptex2pdf.lua
SUBST_SED.shebang=	-e "s,^\#!/usr/bin/env texlua$$,\#!/usr/pkg/bin/texlua,"

post-install:
	${LN} -sf ../share/texmf-dist/scripts/ptex2pdf/ptex2pdf.lua \
		${DESTDIR}${PREFIX}/bin/ptex2pdf

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
