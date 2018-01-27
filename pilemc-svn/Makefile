# $NetBSD: Makefile,v 1.2 2012/10/05 11:31:52 asau Exp $

DISTNAME=	pilemc
PKGNAME=	${DISTNAME}-svn-${VERSION}
CATEGORIES=	math

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://pilemc.hepforge.org/
COMMENT=	Tool for the simulation of pile-up events at HepMC level

SVN_REPOSITORIES=	pilemc
SVN_REPO.pilemc=	http://pilemc.hepforge.org/svn/trunk/

WRKSRC=			${WRKDIR}/$(SVN_MODULE.pilemc)

VERSION=	1.2alpha0
GNU_CONFIGURE=	yes
USE_TOOLS+=	aclocal autoconf automake # gmake gm4
USE_LANGUAGES=	c c++

pre-configure:
	cd ${WRKSRC} &&  ./reconf && ./configure

.include "../../math/gsl/buildlink3.mk"
.include "../../wip/hepmc/buildlink3.mk"
.include "../../wip/mk/svn-package.mk"
.include "../../mk/bsd.pkg.mk"
