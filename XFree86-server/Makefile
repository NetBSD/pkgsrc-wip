# $NetBSD: Makefile,v 1.1.1.1 2003/07/23 20:35:17 xtraeme Exp $
# $Id: Makefile,v 1.1.1.1 2003/07/23 20:35:17 xtraeme Exp $

DISTNAME=	${DISTFILES}
PKGNAME=	XFree86-server-${XFREE86_VERSION}
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XFREE}
DISTFILES=	X430src-1.tgz X430src-2.tgz X430src-3.tgz

MAINTAINER=	xfree86@xtraeme.unixbsd.org
HOMEPAGE=	http://www.xfree86.org/
COMMENT=	XFree86 X server and related programs

USE_BUILDLINK2=		YES
DISTINFO_FILE=		${.CURDIR}/../XFree86-libs/distinfo
PATCHDIR=		${.CURDIR}/../XFree86-libs/patches

XBUILD_DIRS=		lib/font lib/lbxutil lib/Xdmcp lib/Xau \
			programs/Xserver 
XINCLUDE_DIRS=		lib/xkbfile lib/xtrans
XINSTALL_DIRS=		lib/font programs/Xserver
XINSTALL_MAN_DIRS=	programs/Xserver

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "FreeBSD" || ${OPSYS} == "Linux"

.if ${MACHINE_ARCH} == "i386" || ${MACHINE_ARCH} == "alpha"
XBUILD_DIRS+=           lib/XThrStub lib/X11 lib/Xext lib/GL
XINSTALL_DIRS+=         lib/GL/mesa/src/drv
.endif

.endif

.include "../../wip/XFree86/Makefile.common"
.include "../../wip/XFree86-libs/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
