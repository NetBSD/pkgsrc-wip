# $NetBSD: Makefile,v 1.3 2005/04/11 21:16:06 tvierling Exp $
#

DISTNAME=		tsh-0.6
CATEGORIES=		wip shells
MASTER_SITES=		http://www.cr0.net:8040/code/network/
EXTRACT_SUFX=		.tgz

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.cr0.net:8040/code/network/
COMMENT=		Lightweight remote shel wity 128AES and file transfers


BUILD_TARGET=${LOWER_OPSYS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tsh ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/tshd ${PREFIX}/sbin

.include "../../mk/bsd.pkg.mk"
