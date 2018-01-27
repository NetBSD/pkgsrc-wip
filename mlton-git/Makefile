# $NetBSD: Makefile,v 1.14 2012/10/03 15:09:56 asau Exp $

DISTNAME=	mlton
PKGNAME=	mlton-0
CATEGORIES=	lang

MAINTAINER=	oivulf@gmail.com
HOMEPAGE=	http://mlton.org/
COMMENT=	Standard ML whole-program optimizing compiler
LICENSE=	modified-bsd

MAKE_JOBS_SAFE=	no
USE_TOOLS+=	gmake bash

.if defined(MLTON_BOOT) && $(MLTON_BOOT) == "mlton"
BUILD_TARGET=	all
.else # use SML/NJ
BUILD_DEPENDS+=	smlnj-[0-9]*:../../lang/smlnj
BUILD_TARGET=	smlnj-mlton all
.endif
BUILD_DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin

GIT_REPOSITORIES=	mlton
GIT_REPO.mlton=		git://github.com/MLton/mlton.git
WRKSRC=			$(WRKDIR)/mlton

REPLACE_PERL=	lib/mlrisc-lib/MLRISC/Doc/html/mltex2html \
		lib/mlrisc-lib/MLRISC/Doc/html/mltex2html.orig \
		lib/mlrisc-lib/MLRISC/cm/makeallcm \
		lib/mlrisc-lib/MLRISC/cm/makecm
# Fix broken scripts, they should use plain sh:
REPLACE_SH=	lib/smlnj-lib/smlnj-lib/Doc/config.sh \
		bin/platform bin/host-os bin/host-arch
REPLACE_BASH=	bin/mlton-script

# No idea why replace-interpreter can't handle it,
# apply more force and do it manually for now:
SUBST_CLASSES+=			fix-sh
SUBST_STAGE.fix-sh=		pre-configure
SUBST_MESSAGE.fix-sh=		Fixing broken scripts
SUBST_FILES.fix-sh=		$(REPLACE_SH)
#SUBST_SED.fix-sh=		-e '1s|^\#![[:space:]]*[^[:space:]]*sh|\#!${SH}|'
SUBST_SED.fix-sh=		-e '1s|^\#!.*|\#!${SH}|'


.include "../../devel/gmp/buildlink3.mk"
.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
