# $NetBSD: Makefile,v 1.1.1.1 2003/07/23 20:50:33 xtraeme Exp $
# $Id: Makefile,v 1.1.1.1 2003/07/23 20:50:33 xtraeme Exp $

DISTNAME=	# empty
PKGNAME=	XFree86-${XFREE86_VERSION}
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XFREE}
DISTFILES=	# empty

MAINTAINER=	xfree86@xtraeme.unixbsd.org
HOMEPAGE=	http://www.xfree86.org/
COMMENT=	XFree86 meta-package

DEPENDS=	imake-*:../../wip/imake
DEPENDS+=	XFree86-libs-*:../../wip/XFree86-libs
DEPENDS+=	XFree86-clients-*:../../wip/XFree86-clients
DEPENDS+=	XFree86-server-*:../../wip/XFree86-server
DEPENDS+=	XFree86-docs-*:../../wip/XFree86-docs
DEPENDS+=	XFree86-man-*:../../wip/XFree86-man
DEPENDS+=	XFree86-fontsEncodings*:../../wip/XFree86-fontsEncodings
DEPENDS+=	XFree86-fontsCyrillic*:../../wip/XFree86-fontsCyrillic
DEPENDS+=	XFree86-fonts100dpi*:../../wip/XFree86-fonts100dpi
DEPENDS+=       XFree86-fonts75dpi*:../../wip/XFree86-fonts75dpi
DEPENDS+=	XFree86-fontserver*:../../wip/XFree86-fontserver
DEPENDS+=	XFree86-fontsScalable*:../../wip/XFree86-fontsScalable
DEPENDS+=	XFree86-defaultBitmaps*:../../wip/XFree86-defaultBitmaps

USE_BUILDLINK2=		yes
NO_BUILD=		# defined
NO_CHECKSUM=		# defined
NO_MTREE=		# defined
NO_XFREE86_TARGETS=	# defined
NO_CONFIGURE=		# defined

do-install:
	@${RM} ${X11BASE}/bin/fc-cache

.include "../../wip/XFree86/Makefile.common"
.include "../../mk/bsd.pkg.mk"
