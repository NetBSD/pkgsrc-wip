# $NetBSD: Makefile,v 1.6 2003/07/24 04:55:25 blef Exp $

DISTNAME=	# empty
PKGNAME=	XFree86-${XF_VER}
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XFREE}
DISTFILES=	# empty

MAINTAINER=	xfree86@xtraeme.unixbsd.org
HOMEPAGE=	http://www.xfree86.org/
COMMENT=	XFree86 meta-package

DEPENDS=	imake-[0-9]*:../../wip/imake
DEPENDS+=	XFree86-libs-[0-9]*:../../wip/XFree86-libs
DEPENDS+=	XFree86-clients-[0-9]*:../../wip/XFree86-clients
DEPENDS+=	XFree86-server-[0-9]*:../../wip/XFree86-server
DEPENDS+=	XFree86-docs-[0-9]*:../../wip/XFree86-docs
DEPENDS+=	XFree86-man-[0-9]*:../../wip/XFree86-man
DEPENDS+=	XFree86-fontsEncodings-[0-9]*:../../wip/XFree86-fontsEncodings
DEPENDS+=	XFree86-fontsCyrillic-[0-9]*:../../wip/XFree86-fontsCyrillic
DEPENDS+=	XFree86-fonts100dpi-[0-9]*:../../wip/XFree86-fonts100dpi
DEPENDS+=	XFree86-fonts75dpi-[0-9]*:../../wip/XFree86-fonts75dpi
DEPENDS+=	XFree86-fontserver-[0-9]*:../../wip/XFree86-fontserver
DEPENDS+=	XFree86-fontsScalable-[0-9]*:../../wip/XFree86-fontsScalable
DEPENDS+=	XFree86-defaultBitmaps-[0-9]*:../../wip/XFree86-defaultBitmaps

USE_BUILDLINK2=		yes
NO_BUILD=		# defined
NO_CHECKSUM=		# defined
NO_MTREE=		# defined
NO_XFREE86_TARGETS=	# defined
NO_CONFIGURE=		# defined

do-install:
	# empty

.include "../../wip/XFree86/Makefile.common"
.include "../../mk/bsd.pkg.mk"
