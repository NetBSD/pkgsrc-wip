# $NetBSD: Makefile,v 1.5 2009/12/12 16:00:21 asau Exp $

DISTNAME=	mlton
PKGNAME=	mlton-0
CATEGORIES=	lang

MAINTAINER=	oivulf@gmail.com
HOMEPAGE=	http://mlton.org/
COMMENT=	Standard ML whole-program optimizing compiler
LICENSE=	modified-bsd

USE_TOOLS+=	gmake

.if !defined(MLTON_BOOT) || $(MLTON_BOOT) == "mlton"
BUILD_TARGET=	all
.else
# use SML/NJ
BUILD_DEPENDS+=	smlnj-[0-9]*:../../lang/smlnj
BUILD_TARGET=	smlnj-mlton all
.endif

SVN_REPOSITORIES=	mlton
SVN_ROOT.mlton=		svn://mlton.org/mlton/trunk
WRKSRC=		$(WRKDIR)/mlton

.include "../../devel/gmp/buildlink3.mk"
.include "../../wip/mk/svn-package.mk"
.include "../../mk/bsd.pkg.mk"
