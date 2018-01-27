# $NetBSD: Makefile,v 1.3 2012/11/14 00:15:59 othyro Exp $
#

DISTNAME=	atompaw-3.0.1.8
CATEGORIES=	math
MASTER_SITES=	http://www.wfu.edu/~natalie/papers/pwpaw//

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://www.wfu.edu/~natalie/papers/pwpaw//
COMMENT=	Projector Augmented Wave code for electronic structure calculations
LICENSE=	gnu-gpl-v3


CHECK_PORTABILITY_SKIP=	configure
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		perl
USE_LANGUAGES=		c fortran

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
