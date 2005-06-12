# $NetBSD: Makefile,v 1.6 2005/06/12 23:51:19 kristerw Exp $
#

DISTNAME=		ghostpcl_1.38p1
PKGNAME=		ghostpcl-1.38p1
CATEGORIES=		print
MASTER_SITES=		ftp://mirror.cs.wisc.edu/pub/mirrors/ghost/AFPL/GhostPCL/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		dieter.NetBSD@pandora.be
HOMEPAGE=		http://www.artifex.com/downloads/
COMMENT=		PCL-5 and PCL-XL interpreter


USE_TOOLS+=gmake
BUILD_TARGET=pcl6

.if defined(GHOSTPCL_USE_X11)
.  if ${GHOSTPCL_USE_X11} == "YES" || ${GHOSTPCL_USE_X11} == "yes"
MAKE_ENV+=	USE_X11=YES
.include "../../mk/x11.buildlink3.mk"
.  endif
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/main/obj/pcl6 ${PREFIX}/bin
	@${INSTALL_DATA_DIR} ${PREFIX}/share/ghostpcl/fonts
	${INSTALL_DATA} ${WRKSRC}/urwfonts/* ${PREFIX}/share/ghostpcl/fonts

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
