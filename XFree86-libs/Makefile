# $NetBSD: Makefile,v 1.1.1.1 2003/07/23 20:33:46 xtraeme Exp $
# $Id: Makefile,v 1.1.1.1 2003/07/23 20:33:46 xtraeme Exp $

DISTNAME=	${DISTFILES}
PKGNAME=	XFree86-libs-${XFREE86_VERSION}
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XFREE}
DISTFILES+=	X430src-1.tgz X430src-2.tgz X430src-3.tgz \
		X430src-4.tgz

MAINTAINER=	xfree86@xtraeme.unixbsd.org
HOMEPAGE=	http://www.xfree86.org/
COMMENT=	XFree86 Libraries

DEPENDS+=		imake-*:../../wip/imake
USE_BUILDLINK2=         yes

XBUILD_DIRS=		lib nls programs/Xserver/include \
			programs/Xserver/hw/xfree86/parser
XINCLUDE_DIRS=		programs/proxymngr
XINSTALL_DIRS=		include lib nls programs/Xserver/include \
			programs/Xserver/hw/xfree86/parser
XINSTALL_MAN_DIRS=	${XINSTALL_DIRS}

.include "../../wip/XFree86/Makefile.common"
.include "../../fonts/fontconfig/buildlink2.mk"
.include "../../graphics/freetype2/buildlink2.mk"
.include "../../textproc/expat/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
