# $NetBSD: Makefile,v 1.2 2005/04/11 21:14:02 tvierling Exp $
#

DISTNAME=		mim-1.2
CATEGORIES=		mbone
MASTER_SITES=		ftp://limestone.uoregon.edu/pub/videolab/

MAINTAINER=		psham@cs.nmsu.edu
HOMEPAGE=		ftp://limestone.uoregon.edu/pub/videolab/
COMMENT=		Multicast MPEG-I stream viewer

DEPENDS+=		mpg123>=0.59.18:../../audio/mpg123
DEPENDS+=		mtv>=1.2.5:../../graphics/mtv

GNU_CONFIGURE=		yes

post-install:
	${INSTALL_DATA} ${WRKSRC}/docs/mim.1 ${PREFIX}/man/man1/mim.1

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
