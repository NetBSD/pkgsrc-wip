# $NetBSD: Makefile,v 1.4 2012/11/14 00:16:11 othyro Exp $
#

DISTNAME=	lhapdf-5.8.7b2
CATEGORIES=	print
MASTER_SITES=	http://www.hepforge.org/archive/lhapdf/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://www.hepforge.org/archive/lhapdf/
COMMENT=	Les Houches Accord PDF library and interface
LICENSE=	gnu-gpl-v2


CHECK_PORTABILITY_SKIP= configure

GNU_CONFIGURE=	yes
CONFIG_SHELL+=	bash
USE_LANGUAGES=	c c++ fortran fortran77

#.include "../../lang/gcc3-f77/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
