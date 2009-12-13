# $NetBSD: Makefile,v 1.8 2009/12/13 16:21:14 asau Exp $

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

SVN_REPOSITORIES=	mlton
SVN_ROOT.mlton=		svn://mlton.org/mlton/trunk
WRKSRC=		$(WRKDIR)/mlton

.include "../../devel/gmp/buildlink3.mk"
.include "../../wip/mk/svn-package.mk"
.include "../../mk/bsd.pkg.mk"
