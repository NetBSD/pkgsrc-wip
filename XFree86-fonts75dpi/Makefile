# $NetBSD: Makefile,v 1.6 2003/07/24 05:17:58 xtraeme Exp $

DISTNAME=	X430src-4
PKGNAME=	XFree86-fonts75dpi-${XF_VER}
WRKSRC=		${WRKDIR}/xc/fonts/bdf/75dpi
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XFREE}
EXTRACT_SUFX=	.tgz

MAINTAINER=	xfree86@xtraeme.unixbsd.org
HOMEPAGE=	http://www.xfree86.org/
COMMENT=	XFree86 bitmap 75dpi fonts

DEPENDS+=	XFree86-fontsEncodings>=4.3.0:../../wip/XFree86-fontsEncodings

USE_BUILDLINK2=		yes
NO_XFREE86_TARGETS=	# defined

FILESDIR=	${PKGDIR}/../XFree86-fontsEncodings/files

post-extract:
	@${LN} -sf ${FILESDIR}/host.def ${WRKSRC}
	@${LN} -sf ${FILESDIR}/host.def ${WRKDIR}/xc/fonts/encodings
	@${LN} -sf ${FILESDIR}/host.def ${WRKDIR}/xc/fonts/encodings/large

do-configure:
	(cd ${WRKDIR}/xc/fonts/encodings && \
	${IMAKE} -DUseInstalled -I${PREFIX}/lib/X11/config \
		-DTOPDIR=../../.. -DCURDIR=.; \
	${MAKE} Makefiles ; \
	${MAKE} includes ; \
	${MAKE} depend)
	(cd ${WRKSRC} && \
	${IMAKE} -DUseInstalled -I${PREFIX}/lib/X11/config \
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
