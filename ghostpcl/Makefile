# $NetBSD: Makefile,v 1.4 2005/04/11 21:12:27 tvierling Exp $
#

DISTNAME=		ghostpcl_1.38p1
PKGNAME=		ghostpcl-1.38p1
CATEGORIES=		print
MASTER_SITES=		ftp://mirror.cs.wisc.edu/pub/mirrors/ghost/AFPL/GhostPCL/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		dieter.NetBSD@pandora.be
HOMEPAGE=		http://www.artifex.com/downloads/
COMMENT=		PCL-5 and PCL-XL interpreter


USE_GNU_TOOLS+=make
BUILD_TARGET=pcl6

.if defined(GHOSTPCL_USE_X11)
.  if ${GHOSTPCL_USE_X11} == "YES" || ${GHOSTPCL_USE_X11} == "yes"
USE_X11=	YES
MAKE_ENV+=	USE_X11=${USE_X11}
.  endif
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/main/obj/pcl6 ${PREFIX}/bin
	@${INSTALL_DATA_DIR} ${PREFIX}/share/ghostpcl/fonts
	${INSTALL_DATA} ${WRKSRC}/urwfonts/* ${PREFIX}/share/ghostpcl/fonts

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
