# $NetBSD: Makefile,v 1.1.1.1 2004/10/13 16:21:55 poppnk Exp $
#

DISTNAME=		hping3-alpha-2
CATEGORIES=		wip net
MASTER_SITES=		http://wiki.hping.org/uploadedfiles/101/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://wiki.hping.org/uploadedfiles/101/
COMMENT=		Command-line oriented TCP/IP packet assembler/analyzer

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
HAS_CONFIGURE=		yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/hping3 ${PREFIX}/sbin/
	${INSTALL_MAN} ${WRKSRC}/docs/hping3.8 ${PREFIX}/man/man8/

.include "../../lang/tcl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
