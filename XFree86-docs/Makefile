# $NetBSD: Makefile,v 1.3 2003/07/24 04:28:31 xtraeme Exp $

DISTNAME=	${DISTFILES}
PKGNAME=	XFree86-docs-${XFREE86_VERSION}
WRKSRC=		${WRKDIR}/xc/doc/specs
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XFREE}
DISTFILES+=	X430src-1.tgz X430src-6.tgz

MAINTAINER=	xfree86@xtraeme.unixbsd.org
HOMEPAGE=	http://www.xfree86.org/
COMMENT=	XFree86 Documentation

DEPENDS=	imake>=4.3.0:../../wip/imake

USE_BUILDLINK2=		yes
PROJECTROOT=		-DProjectRoot=${PREFIX}
NO_XFREE86_TARGETS=	# defined

pre-configure:
	@${LN} -sf ${FILESDIR}/host.def ${WRKSRC}

do-configure:
	( cd ${WRKSRC}; \
	${IMAKE} -DUseInstalled ${PROJECTROOT} -I. -I${PREFIX}/lib/X11/config \
		-DTOPDIR=../.. -DCURDIR=.; \
	${MAKE} Makefiles ; \
	${MAKE} includes ; \
	${MAKE} depend )

.include "../../wip/XFree86/Makefile.common"
.include "../../mk/bsd.pkg.mk"
