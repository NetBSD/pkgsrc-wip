# $NetBSD: Makefile,v 1.10 2010/02/24 18:03:03 asau Exp $

DISTNAME=	mlton
PKGNAME=	mlton-0
CATEGORIES=	lang

MAINTAINER=	oivulf@gmail.com
HOMEPAGE=	http://mlton.org/
COMMENT=	Standard ML whole-program optimizing compiler
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_JOBS_SAFE=	no
USE_TOOLS+=	gmake

.if defined(MLTON_BOOT) && $(MLTON_BOOT) == "mlton"
BUILD_TARGET=	all
.else # use SML/NJ
BUILD_DEPENDS+=	smlnj-[0-9]*:../../lang/smlnj
BUILD_TARGET=	smlnj-mlton all
.endif
BUILD_DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin

SVN_REPOSITORIES=	mlton
SVN_ROOT.mlton=		svn://mlton.org/mlton/trunk
WRKSRC=		$(WRKDIR)/mlton

REPLACE_PERL=	lib/mlrisc-lib/MLRISC/Doc/html/mltex2html \
		lib/mlrisc-lib/MLRISC/Doc/html/mltex2html.orig \
		lib/mlrisc-lib/MLRISC/cm/makeallcm \
		lib/mlrisc-lib/MLRISC/cm/makecm
REPLACE_SH=	lib/smlnj-lib/smlnj-lib/Doc/config.sh

.include "../../devel/gmp/buildlink3.mk"
.include "../../wip/mk/svn-package.mk"
.include "../../mk/bsd.pkg.mk"
