# $NetBSD: Makefile,v 1.3 2003/07/24 00:56:51 blef Exp $

DISTNAME=	X430src-4
PKGNAME=	XFree86-fontsEncodings-${XFREE86_VERSION}
WRKSRC=		${WRKDIR}/xc/fonts/encodings
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XFREE}
EXTRACT_SUFX=	.tgz

MAINTAINER=	xfree86@xtraeme.unixbsd.org
HOMEPAGE=	http://www.xfree86.org/
COMMENT=	XFree86 Encoding fonts

DEPENDS=	XFree86-clients-[0-9]*:../../wip/XFree86-clients

USE_BUILDLINK2=		yes
NO_XFREE86_TARGETS=	#defined
PROJECTROOT=		-DProjectRoot=${PREFIX}

post-extract:
	@${LN} -sf ${FILESDIR}/host.def ${WRKSRC}
	@${LN} -sf ${LOCALBASE}/bin/fc-cache ${X11BASE}/bin

do-configure:
	(cd ${WRKSRC} && \
	${IMAKE} -DUseInstalled ${PROJECTROOT} -I${PREFIX}/lib/X11/config \
		-DTOPDIR=../../.. -DCURDIR=.; \
	${MAKE} Makefiles ; \
	${MAKE} includes ; \
	${MAKE} depend)

.include "../../wip/XFree86/Makefile.common"
.include "../../mk/bsd.pkg.mk"
