# $NetBSD: Makefile,v 1.5 2012/10/07 17:06:27 asau Exp $
#

DISTNAME=		tsh-0.6
CATEGORIES=		shells
MASTER_SITES=		http://www.cr0.net:8040/code/network/
EXTRACT_SUFX=		.tgz

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.cr0.net:8040/code/network/
COMMENT=		Lightweight remote shel wity 128AES and file transfers


BUILD_TARGET=${LOWER_OPSYS}

INSTALLATION_DIRS=	bin sbin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tsh ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/tshd ${DESTDIR}${PREFIX}/sbin

.include "../../mk/bsd.pkg.mk"
