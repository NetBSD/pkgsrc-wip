# $NetBSD: Makefile,v 1.8 2003/07/25 04:01:49 xtraeme Exp $

DISTNAME=	${DISTFILES}
PKGNAME=	imake-${XF_VER}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_XFREE}
DISTFILES=	X430src-1.tgz X430src-3.tgz

MAINTAINER=	xfree86@xtraeme.unixbsd.org
HOMEPAGE=	http://www.xfree86.org/
COMMENT=	Imake and other utilities from XFree86

USE_BUILDLINK2=	YES

INSTALL_TARGET=	install install.man

NO_XFREE86_TARGETS=	# defined
FAKE_XFREE86_DEPS=	# defined

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Linux"
DEPENDS+=	bison-[0-9]*:../../devel/bison
DEPENDS+=	flex-[0-9]*:../../devel/flex
.endif

.include "../../wip/XFree86/Makefile.common"
.include "../../mk/bsd.pkg.mk"
