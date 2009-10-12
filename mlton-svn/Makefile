# $NetBSD: Makefile,v 1.3 2009/10/12 18:33:17 fulviociriaco Exp $

DISTNAME= mlton
PKGNAME= mlton-1
PKGREVISION=${_SVN_PKGVERSION:S/.//g}

CATEGORIES= lang

MAINTAINER= oivulf@gmail.com
HOMEPAGE= http://mlton.org/
COMMENT= Mlton provides an sml optimizing compiler
LICENSE= modified-bsd

mywild = mlton-*
installq= pkg_info -E ${mywild}
isinstalled != ${installq}

USE_TOOLS+= gmake

.if (!defined(mlton_boot) ||  ${mlton_boot} == mlton ) 
BUILD_TARGET= all
#BUILD_DEPENDS+=  mlton>=svnnb20091009*:../../wip/mlton-svn
.include "../../wip/mlton-svn/buildlink3.mk"
.elif ${mlton_boot} == smlnj
BUILD_TARGET=smlnj-mlton all
BUILD_DEPENDS+=  smlnj*:../../lang/smlnj
.else
	error
.endif
INSTALL_TARGET= install

SVN_REPOSITORIES= mlton
SVN_ROOT.mlton= svn://mlton.org/mlton/trunk
WRKSRC= ${WRKDIR}/mlton


.include "../../devel/gmp/buildlink3.mk"
.include "../../wip/mk/svn-package.mk"
.include "../../mk/bsd.pkg.mk"

