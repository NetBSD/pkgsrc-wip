# $NetBSD: Makefile,v 1.5 2012/10/07 20:11:10 asau Exp $

DISTNAME=		mim-1.2
PKGNAME=		xmim-1.2
CATEGORIES=		mbone
#MASTER_SITES=		ftp://limestone.uoregon.edu/pub/videolab/

MAINTAINER=		psham@cs.nmsu.edu
#HOMEPAGE=		http://videolab.uoregon.edu/
COMMENT=		GUI interface for multicast MPEG-I stream viewer

WRKSRC=			${WRKDIR}/mim-1.2
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-gui
CONFIGURE_ARGS+=	--disable-gtktest

post-extract:
	${RM} -f ${WRKSRC}/config.cache

post-install:
	${INSTALL_DATA} ${WRKSRC}/docs/xmim.1 ${PREFIX}/${PKGMANDIR}/man1/xmim.1

.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
