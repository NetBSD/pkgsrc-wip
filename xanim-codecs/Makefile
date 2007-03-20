# $NetBSD: Makefile,v 1.6 2007/03/20 21:16:57 shattered Exp $

DISTNAME=
PKGNAME=	xanim-codecs-19990322
CATEGORIES=	multimedia
MASTER_SITES=	ftp://ftp.informatik.uni-hamburg.de/pub/soft/graphics/xanim/dlls/ \
		ftp://ftp.mayn.de/pub/really_old_stuff/unix/graphic/xanim/dll-glibc2.0/ \
		ftp://ftp.sai.msu.su/pub/unix/mpeg/xanim/dlls/ \
		ftp://ftp.nstu.ru/pub/mirrors/xanim.va.pubnix.com/dlls/
DISTFILES=	${CODEC_DLL_FILES}

MAINTAINER=	shattered@users.sourceforge.net
COMMENT=	Dynamically loadable codecs for XAnim
HOMEPAGE=	http://xanim.polter.net/

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
	${INSTALL_DATA} ${WRKSRC}/*.xa ${PREFIX}/lib/xanim

.include "../../mk/bsd.pkg.mk"
