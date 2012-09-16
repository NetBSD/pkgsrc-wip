# $NetBSD: Makefile,v 1.1 2012/09/16 09:45:47 jihbed Exp $
#

DISTNAME=	atompaw-3.0.1.8
CATEGORIES=	physics
MASTER_SITES=	http://www.wfu.edu/~natalie/papers/pwpaw//

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://www.wfu.edu/~natalie/papers/pwpaw//
COMMENT= Projector Augmented Wave code for electronic structure calculations
LICENSE=	gnu-gpl-v3


PKG_DESTDIR_SUPPORT=	user-destdir

CHECK_PORTABILITY_SKIP= configure
GNU_CONFIGURE=	yes
USE_LIBTOOL= yes
USE_TOOLS+=	perl
USE_LANGUAGES=	c fortran

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
