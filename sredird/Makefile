# $NetBSD: Makefile,v 1.3 2004/02/20 20:27:50 tvierling Exp $
#

DISTNAME=		sredird-2.0.0
CATEGORIES=		sysutils
MASTER_SITES=		http://www.pcmicro.com/sredird/

MAINTAINER=		tv@duh.org
HOMEPAGE=		http://www.pcmicro.com/sredird/
COMMENT=		RFC2217 compliant serial port redirector

USE_BUILDLINK3=		yes

MAKE_FLAGS=		CC="${CC}" CFLAGS="${CFLAGS}"
ALL_TARGET=		sredird

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sredird ${PREFIX}/libexec/sredird
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/sredird.README

.include "../../mk/bsd.pkg.mk"
