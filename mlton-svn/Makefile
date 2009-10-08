# $NetBSD: Makefile,v 1.1 2009/10/08 06:11:12 fulviociriaco Exp $

DISTNAME= mlton
PKGNAME= mlton-svn
PKGREVISION=${_SVN_PKGVERSION:S/.//g}

CATEGORIES= lang

MAINTAINER= oivulf@gmail.com
HOMEPAGE= http://mlton.org/
COMMENT= Mlton provides an sml optimizing compiler
LICENSE= modified-bsd

USE_TOOLS+= gmake

.if !defined(mlton_boot)
BUILD_TARGET= all
BUILD_DEPENDS+=  mlton*:../../wip/mlton-svn
.elif ${mlton_boot} == mlton
BUILD_TARGET= all
BUILD_DEPENDS+=  mlton*:../../wip/mlton-svn
.elif ${mlton_boot} == smlnj
BUILD_TARGET=smlnj-mlton all
BUILD_DEPENDS+=  smlnj*:../../lang/smlnj
.endif

INSTALL_TARGET= install

SVN_REPOSITORIES= mlton
SVN_ROOT.mlton= svn://mlton.org/mlton/trunk
WRKSRC= ${WRKDIR}/mlton

#.include "options.mk"

.include "../../devel/gmp/buildlink3.mk"
.include "../../wip/mk/svn-package.mk"
.include "../../mk/bsd.pkg.mk"

