# $NetBSD: Makefile,v 1.1.1.1 2011/04/02 22:10:45 jihbed Exp $
#

DISTNAME=	Minuit2-5.28.00
PKGNAME=	${DISTNAME:S/M/m/}
CATEGORIES=	physics
MASTER_SITES=	http://www.cern.ch/mathlibs/sw/5_28_00/Minuit2/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://seal.web.cern.ch/seal/snapshot/work-packages/mathlibs/minuit/
COMMENT=	MINUIT is a physics analysis tool for function minimization

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++

.include "../../mk/bsd.pkg.mk"
