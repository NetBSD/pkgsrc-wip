# $NetBSD: Makefile,v 1.93 2020/04/08 15:22:07 rhialto Exp $

# https://www.kermitproject.org/ftp/kermit/test/tar/cku10.0-beta04.tar.gz
VERSION=	10.0
VERSIONSEP=	-
VERSIONRC=	beta04
DISTNAME=	cku${VERSION}${VERSIONSEP}${VERSIONRC}
PKGNAME=	kermit-${VERSION}${VERSIONRC}
CATEGORIES=	comms
MASTER_SITES=	https://www.kermitproject.org/ftp/kermit/test/tar/

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	https://www.kermitproject.org/
COMMENT=	Network and serial communication, file transfer, and scripting utility

LICENSE=	modified-bsd

.include "../../mk/bsd.prefs.mk"

# The tarball just has files, no directory.
# \todo Create "kermit" in ${WRKDIR} and unpack into it.
WRKSRC=		${WRKDIR}
BUILD_DEFS+=	KFLAGS LIBS
MAKE_ENV+=	prefix=${PREFIX} KFLAGS=${KFLAGS:Q} LIBS=${LIBS:Q}
MAKE_FILE=	makefile

#KFLAGS+=	-DNODEBUG -DNOOLDMODEMS
KFLAGS+=	${BUILDLINK_CPPFLAGS}

LIBS+=		${BUILDLINK_LDADD.termcap}
LIBS+=		${BUILDLINK_LDFLAGS}

.include "options.mk"

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/termcap.buildlink3.mk"

.if ${OPSYS} == "Darwin"
.  if !empty(OS_VERSION:M??.*)
BUILD_TARGET_OPSYS=	macosx10.6
.  elif !empty(OS_VERSION:M9.*)
BUILD_TARGET_OPSYS=	macosx10.5
.  elif !empty(OS_VERSION:M8.*)
BUILD_TARGET_OPSYS=	macosx10.4
.  elif empty(OS_VERSION:M7.*)
BUILD_TARGET_OPSYS=	macosx103.9
.  else
BUILD_TARGET_OPSYS=	macosx10
.  endif
.elif ${OPSYS} == "Linux"
BUILD_TARGET_OPSYS=	linux
MAKE_ENV+=		HAVE_LIBCURSES=-l${BUILDLINK_LIBNAME.curses}
.  if ${CURSES_TYPE} == "ncurses"
MAKE_ENV+=		HAVE_CURSES=-DCK_NCURSES
.  else
MAKE_ENV+=		HAVE_CURSES=-DCK_NCURSES
.  endif
.elif ${OPSYS} == "SunOS"
BUILD_TARGET_OPSYS=	solaris11g
.else
BUILD_TARGET_OPSYS=	netbsd
.endif

BUILD_TARGET=	${BUILD_TARGET_OPSYS}${BUILD_TARGET_OPTIONS:ts}

.include "../../mk/bsd.pkg.mk"
