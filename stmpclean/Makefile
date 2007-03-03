# $NetBSD: Makefile,v 1.5 2007/03/03 11:04:47 shattered Exp $
#

DISTNAME=		stmpclean-0.3
CATEGORIES=		sysutils
MASTER_SITES=		http://shlang.com/stmpclean/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://shlang.com/stmpclean/
COMMENT=		Secure /tmp cleaner


do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/stmpclean ${PREFIX}/sbin/stmpclean
	${INSTALL_DATA} ${WRKSRC}/stmpclean.8 ${PREFIX}/${PKGMANDIR}/man8/

.include "../../mk/bsd.pkg.mk"
