# $NetBSD: Makefile,v 1.6 2003/07/24 05:05:56 xtraeme Exp $

DISTNAME=	X430src-4
PKGNAME=	XFree86-fontsEncodings-${XF_VER}
WRKSRC=		${WRKDIR}/xc/fonts/encodings
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XFREE}
EXTRACT_SUFX=	.tgz

MAINTAINER=	xfree86@xtraeme.unixbsd.org
HOMEPAGE=	http://www.xfree86.org/
COMMENT=	XFree86 Encoding fonts

DEPENDS=	XFree86-clients>=4.3.0:../../wip/XFree86-clients

USE_BUILDLINK2=		yes
NO_XFREE86_TARGETS=	# defined

post-extract:
	@${LN} -sf ${FILESDIR}/host.def ${WRKSRC}
	@${LN} -sf ${LOCALBASE}/bin/fc-cache ${X11BASE}/bin

do-configure:
	(cd ${WRKSRC} && \
	${IMAKE} -DUseInstalled -I${PREFIX}/lib/X11/config \
		-DTOPDIR=../../.. -DCURDIR=.; \
	${MAKE} Makefiles ; \
	${MAKE} includes ; \
	${MAKE} depend)

.include "../../wip/XFree86/Makefile.common"
.include "../../mk/bsd.pkg.mk"
