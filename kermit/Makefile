# $NetBSD: Makefile,v 1.93 2020/04/08 15:22:07 rhialto Exp $

# https://www.kermitproject.org/ftp/kermit/test/tar/index.html
# https://www.kermitproject.org/ftp/kermit/test/tar/cku405-beta09.tar.gz
# https://www.kermitproject.org/ftp/kermit/test/tar/cku416-beta12.tar.gz
VERSION=	10.0
VERSIONDIST=	416
VERSIONSEP=	-
VERSIONRC=	beta12
DISTNAME=	cku${VERSIONDIST}${VERSIONSEP}${VERSIONRC}
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

# \todo Enhance for non-standard mandir.

#KFLAGS+=	-DNODEBUG -DNOOLDMODEMS
KFLAGS+=	${BUILDLINK_CPPFLAGS}

LIBS+=		${BUILDLINK_LDADD.termcap}
LIBS+=		${BUILDLINK_LDFLAGS}

.include "options.mk"

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/termcap.buildlink3.mk"

.if ${OPSYS} == "Darwin"
# Assume >= 10.12 for now.
BUILD_TARGET_OPSYS=	macos
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

.include "../../mk/pam.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
