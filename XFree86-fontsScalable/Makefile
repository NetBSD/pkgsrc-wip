# $NetBSD: Makefile,v 1.3 2003/07/24 00:14:09 blef Exp $

DISTNAME=	${DISTFILES}
PKGNAME=	XFree86-fontsScalable-${XFREE86_VERSION}
WRKSRC=		${WRKDIR}/xc/fonts
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XFREE}
DISTFILES=	X430src-4.tgz X430src-5.tgz

MAINTAINER=	xfree86@xtraeme.unixbsd.org
HOMEPAGE=	http://www.xfree86.org/
COMMENT=	XFree86 scalable fonts

DEPENDS=	XFree86-clients*:../../wip/XFree86-clients
DEPENDS+=	XFree86-fontsEncodings*:../../wip/XFree86-fontsEncodings

USE_BUILDLINK2=		yes
NO_XFREE86_TARGETS=	#defined
PROJECTROOT=            -DProjectRoot=${PREFIX}

do-configure:
	(cd ${WRKDIR}/xc/fonts/encodings && \
	${IMAKE} -DUseInstalled ${PROJECTROOT} -I${PREFIX}/lib/X11/config \
		-DTOPDIR=../.. -DCURDIR=.; \
	${MAKE} Makefiles ; \
	${MAKE} includes ; \
	${MAKE} depend)

	(cd ${WRKSRC} && \
	${IMAKE} -DUseInstalled ${PROJECTROOT} -I${PREFIX}/lib/X11/config \
		-DTOPDIR=../.. -DCURDIR=.; \
	${MAKE} Makefiles ; \
	${MAKE} includes ; \
	${MAKE} depend)

pre-build:
	(cd ${WRKDIR}/xc/fonts/encodings && \
	${MAKE} all)

pre-install:
	${LN} -sf ${WRKDIR}/xc/fonts ${WRKDIR}/fonts

.include "../../wip/XFree86/Makefile.common"
.include "../../mk/bsd.pkg.mk"
