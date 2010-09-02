# $NetBSD: Makefile,v 1.1.1.1 2010/09/02 12:05:14 jihbed Exp $
#

DISTNAME=	nauty24r2
PKGNAME=	nauty-24r2
CATEGORIES=	math
MASTER_SITES=	http://cs.anu.edu.au/~bdm/nauty/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://cs.anu.edu.au/~bdm/nauty/
COMMENT=	Brendan McKay's graph isomorphism tester
#LICENSE=	# TODO: (see mk/license.mk)

MAKE_JOBS_SAFE= no

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
MAKE_FILE=	makefile
USE_TOOLS+=	gmake
USE_LANGUAGES=	c

PROGFILES=  NRswitchg complg dreadnaut gentourng pickg 			\
	    addedgeg copyg dretog labelg planarg amtog countg 		\
	    genbg listg shortg biplabg deledgeg geng multig showg 	\
	    arg directg genrang newedgeg

INSTALLATION_DIRS= bin

do-install:

.for progf in ${PROGFILES}
	${INSTALL_PROGRAM} ${WRKSRC}/${progf} ${DESTDIR}${PREFIX}/bin
.endfor


.include "../../mk/bsd.pkg.mk"
