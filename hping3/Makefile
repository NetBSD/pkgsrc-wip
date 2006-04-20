# $NetBSD: Makefile,v 1.4 2006/04/20 13:36:36 cheusov Exp $
#

DISTNAME=		hping3-alpha-2
CATEGORIES=		net
MASTER_SITES=		http://wiki.hping.org/uploadedfiles/101/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://wiki.hping.org/uploadedfiles/101/
COMMENT=		Command-line oriented TCP/IP packet assembler/analyzer

USE_PKGLOCALEDIR=	yes
HAS_CONFIGURE=		yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/hping3 ${PREFIX}/sbin/
	${INSTALL_MAN} ${WRKSRC}/docs/hping3.8 ${PREFIX}/${PKGMANDIR}/man8/

.include "../../lang/tcl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
