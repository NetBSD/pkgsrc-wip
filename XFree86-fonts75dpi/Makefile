# $NetBSD: Makefile,v 1.2 2003/07/23 22:30:50 blef Exp $
# $Id: Makefile,v 1.2 2003/07/23 22:30:50 blef Exp $

DISTNAME=	X430src-4
PKGNAME=	XFree86-fonts75dpi-${XFREE86_VERSION}
WRKSRC=		${WRKDIR}/xc/fonts/bdf/75dpi
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XFREE}
EXTRACT_SUFX=	.tgz

MAINTAINER=	xfree86@xtraeme.unixbsd.org
HOMEPAGE=	http://www.xfree86.org/
COMMENT=	XFree86 bitmap 75dpi fonts

DEPENDS=	XFree86-clients*:../../wip/XFree86-clients
DEPENDS+=	XFree86-fontsEncodings*:../../wip/XFree86-fontsEncodings

USE_BUILDLINK2=		yes
PROJECTROOT=		-DProjectRoot=${PREFIX}
NO_XFREE86_TARGETS=	#defined

FILESDIR=	${PKGDIR}/../XFree86-fontsEncodings/files

post-extract:
	@${LN} -sf ${FILESDIR}/host.def ${WRKSRC}
	@${LN} -sf ${FILESDIR}/host.def ${WRKDIR}/xc/fonts/encodings
	@${LN} -sf ${FILESDIR}/host.def ${WRKDIR}/xc/fonts/encodings/large

do-configure:
	(cd ${WRKDIR}/xc/fonts/encodings && \
	${IMAKE} -DUseInstalled ${PROJECTROOT} -I${PREFIX}/lib/X11/config \
		-DTOPDIR=../../.. -DCURDIR=.; \
	${MAKE} Makefiles ; \
	${MAKE} includes ; \
	${MAKE} depend)
	(cd ${WRKSRC} && \
	${IMAKE} -DUseInstalled ${PROJECTROOT} -I${PREFIX}/lib/X11/config \
		-DTOPDIR=../../.. -DCURDIR=.; \
	${MAKE} Makefiles ; \
	${MAKE} includes ; \
	${MAKE} depend)

pre-build:
	@${MV} ${WRKDIR}/xc/fonts/encodings/large/Makefile \
		${WRKDIR}/xc/fonts/encodings/large/Makefile.in
	@${SED} -e "s|/usr/X11R6|${PREFIX}|g" \
	< ${WRKDIR}/xc/fonts/encodings/large/Makefile.in > \
	${WRKDIR}/xc/fonts/encodings/large/Makefile

	(cd ${WRKDIR}/xc/fonts/encodings && \
	 ${MAKE} all)

.include "../../wip/XFree86/Makefile.common"
.include "../../mk/bsd.pkg.mk"
