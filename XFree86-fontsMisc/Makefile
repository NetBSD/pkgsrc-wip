# $NetBSD: Makefile,v 1.2 2003/11/25 19:46:19 jeremy-c-reed Exp $

DISTNAME=	${DISTFILES}
PKGNAME=	XFree86-fontsMisc-${XF_VER}
WRKSRC=		${WRKDIR}/xc/fonts/bdf/misc
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XFREE}
DISTFILES=	X430src-1.tgz X430src-4.tgz

MAINTAINER=	xfree86@blef.org
HOMEPAGE=	http://www.xfree86.org/
COMMENT=	XFree86 default bitmap fonts

DEPENDS=	XFree86-fontsEncodings>=4.3.0:../../wip/XFree86-fontsEncodings

USE_BUILDLINK2=		yes
NO_XFREE86_TARGETS=	# defined
EXTRACT_ONLY=		X430src-4.tgz

FILESDIR=	${PKGDIR}/../XFree86-fontsEncodings/files

post-extract:
	cd ${WRKDIR} && \
		${GUNZIP_CMD} -c ${DISTDIR}/X430src-1.tgz | ${GTAR} -xf - \
		xc/extras/fonts/arabic24 xc/extras/fonts/ClearlyU;
	@${SED} \
		-e "s|@PREFIX@|${X11PREFIX}|g" \
		-e "s|@MAKE@|${MAKE_PROGRAM}|g" \
		-e "s|@IMAKE@|${IMAKE}|g" \
		${FILESDIR}/host.def > ${WRKSRC}/host.def
	@${LN} -sf ${WRKSRC}/host.def ${WRKDIR}/xc/fonts/encodings
	@${LN} -sf ${WRKSRC}/host.def ${WRKDIR}/xc/fonts/encodings/large

do-configure:
	(cd ${WRKDIR}/xc/fonts/encodings && \
	${IMAKE} -DUseInstalled -I${PREFIX}/lib/X11/config \
		-DTOPDIR=../.. -DCURDIR=.; \
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
