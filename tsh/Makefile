# $NetBSD: Makefile,v 1.6 2012/11/25 23:32:31 othyro Exp $
#

DISTNAME=		tsh-0.6
CATEGORIES=		shells
MASTER_SITES=		http://www.cr0.net:8040/code/network/
EXTRACT_SUFX=		.tgz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.cr0.net:8040/code/network/
COMMENT=		Lightweight remote shel wity 128AES and file transfers


BUILD_TARGET=	${LOWER_OPSYS}

INSTALLATION_DIRS=	bin sbin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tsh ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/tshd ${DESTDIR}${PREFIX}/sbin

.include "../../mk/bsd.pkg.mk"
