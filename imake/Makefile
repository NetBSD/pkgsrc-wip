# $NetBSD: Makefile,v 1.1.1.1 2003/07/23 20:30:44 xtraeme Exp $
# $Id: Makefile,v 1.1.1.1 2003/07/23 20:30:44 xtraeme Exp $

DISTNAME=	${DISTFILES}
PKGNAME=	imake-${XFREE86_VERSION}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_XFREE}
DISTFILES=      X430src-1.tgz X430src-3.tgz

MAINTAINER=	xfree86@xtraeme.unixbsd.org
HOMEPAGE=	http://www.xfree86.org/
COMMENT=	Imake and other utilities from XFree86

USE_BUILDLINK2=	YES
USE_PERL5=	YES

INSTALL_TARGET=	install install.man

NO_XFREE86_TARGETS=	# defined
FAKE_XFREE86_DEPS=	# defined

.include "../../wip/XFree86/Makefile.common"
.include "../../mk/bsd.pkg.mk"
