# $NetBSD: Makefile,v 1.4 2006/11/26 23:05:32 shattered Exp $

DISTNAME=
PKGNAME=	xanim-codecs-19990322
CATEGORIES=	multimedia
MASTER_SITES=	ftp://ftp.informatik.uni-hamburg.de/pub/soft/graphics/xanim/dlls/ \
		ftp://ftp.mayn.de/pub/unix/graphic/xanim/dll-glibc2.0/ \
		ftp://ftp.sai.msu.su/pub/unix/mpeg/xanim/dlls/ \
		ftp://ftp.nstu.ru/pub/mirrors/xanim.va.pubnix.com/dlls/
DISTFILES=	${CODEC_DLL_FILES}

MAINTAINER=	shattered@users.sourceforge.net
COMMENT=	Dynamically loadable codecs for XAnim

DIST_SUBDIR=	xanim
NO_BUILD=	YES
WRKSRC=		${WRKDIR}
INSTALLATION_DIRS+=	lib/xanim share/doc/xanim
ONLY_FOR_PLATFORM=	*-*-i386 # *-*-alpha *-*-powerpc *-*-sparc *-*-sgimips

.include "Makefile.codecs"

USE_X11BASE=	YES
PLIST_SRC+=	PLIST.${MACHINE_ARCH}

BUILD_DEFS+=	XANIM_DLL_CODECS

do-install:
	${INSTALL_DATA} ${WRKSRC}/*.readme ${PREFIX}/share/doc/xanim
	${INSTALL_DATA_DIR} ${PREFIX}/lib/xanim
	${INSTALL_DATA} ${WRKSRC}/*.xa ${PREFIX}/lib/xanim

.include "../../mk/bsd.pkg.mk"
