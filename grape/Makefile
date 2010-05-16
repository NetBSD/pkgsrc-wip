# $NetBSD: Makefile,v 1.1.1.1 2010/05/16 16:05:26 jihbed Exp $
#

DISTNAME=	grape4r3
PKGNAME=	${DISTNAME:S/4r3//}-4r3
CATEGORIES=	math
MASTER_SITES=	http://www.maths.qmul.ac.uk/~leonard/grape/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://www.maths.qmul.ac.uk/~leonard/grape/
COMMENT=	GRAPE is a GAP package for computing with graphs and groups
#LICENSE=	# TODO: (see mk/license.mk)


PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/grape
HAS_CONFIGURE=	yes
USE_LANGUAGES=	c fortran

do-configure:
	cd ${WRKSRC} && ${SH} configure

.include "../../mk/bsd.pkg.mk"
