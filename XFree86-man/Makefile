# $NetBSD: Makefile,v 1.1.1.1 2003/07/23 20:37:01 xtraeme Exp $
# $Id: Makefile,v 1.1.1.1 2003/07/23 20:37:01 xtraeme Exp $

DISTNAME=	X430src-1
PKGNAME=	XFree86-man-${XFREE86_VERSION}
WRKSRC=         ${WRKDIR}/xc/doc/man
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XFREE}
EXTRACT_SUFX=	.tgz

MAINTAINER=	xfree86@xtraeme.unixbsd.org
HOMEPAGE=	http://www.xfree86.org/
COMMENT=	XFree86 Manuals

DEPENDS=	imake-*:../../wip/imake

USE_BUILDLINK2=		yes

PROJECTROOT=		-DProjectRoot=${PREFIX}
NO_XFREE86_TARGETS=	#defined
INSTALL_TARGET=		install.man

do-configure:
	(cd ${WRKSRC} ; \
	${IMAKE} -DUseInstalled ${PROJECTROOT} -I. -I${PREFIX}/lib/X11/config \
		-DTOPDIR=../.. -DCURDIR=.; \
	${MAKE} Makefiles ; \
	${MAKE} includes ; \
	${MAKE} depend)

.include "../../wip/XFree86/Makefile.common"
.include "../../mk/bsd.pkg.mk"
