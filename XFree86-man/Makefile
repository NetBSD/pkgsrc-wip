# $NetBSD: Makefile,v 1.6 2003/09/01 23:57:53 blef Exp $

DISTNAME=	X430src-1
PKGNAME=	XFree86-man-${XF_VER}
WRKSRC=		${WRKDIR}/xc/doc/man
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XFREE}
EXTRACT_SUFX=	.tgz

MAINTAINER=	xfree86@blef.org
HOMEPAGE=	http://www.xfree86.org/
COMMENT=	XFree86 Manuals

DEPENDS=	imake>=4.3.0:../../wip/imake

USE_BUILDLINK2=		yes

NO_XFREE86_TARGETS=	# defined
INSTALL_TARGET=		install.man

do-configure:
	(cd ${WRKSRC} ; \
	${IMAKE} -DUseInstalled -I. -I${PREFIX}/lib/X11/config \
		-DTOPDIR=../.. -DCURDIR=.; \
	${MAKE} Makefiles ; \
	${MAKE} includes ; \
	${MAKE} depend)

.include "../../wip/XFree86/Makefile.common"
.include "../../mk/bsd.pkg.mk"
