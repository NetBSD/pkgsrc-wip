# $NetBSD: Makefile,v 1.1.1.1 2005/12/10 17:32:23 shattered Exp $

DISTNAME=
PKGNAME=	xanim-codecs-19990322
CATEGORIES=	multimedia
MASTER_SITES=	ftp://ftp.informatik.uni-hamburg.de/pub/soft/graphics/xanim/dlls/
DISTFILES=	${CODEC_DLL_FILES}

MAINTAINER=	shattered@users.sourceforge.net
COMMENT=	Dynamically loadable codecs for XAnim

DIST_SUBDIR=	xanim
NO_BUILD=	YES
WRKSRC=		${WRKDIR}
ONLY_FOR_PLATFORM=	*-*-i386 # *-*-alpha *-*-powerpc *-*-sparc *-*-sgimips

.include "Makefile.codecs"

USE_X11BASE=	YES
PLIST_SRC+=	PLIST.${MACHINE_ARCH}

BUILD_DEFS+=	XANIM_DLL_CODECS

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/xanim
	${INSTALL_DATA} ${WRKSRC}/*.readme ${PREFIX}/share/doc/xanim
	${INSTALL_DATA_DIR} ${PREFIX}/lib/xanim
	${INSTALL_DATA} ${WRKSRC}/*.xa ${PREFIX}/lib/xanim

.include "../../mk/bsd.pkg.mk"
