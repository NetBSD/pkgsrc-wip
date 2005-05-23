# $NetBSD: Makefile,v 1.1.1.1 2005/05/23 20:21:27 poppnk Exp $
#

DISTNAME=		atftp-0.7
CATEGORIES=		wip net
MASTER_SITES=		ftp://ftp.mamalinux.com/pub/atftp/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://freshmeat.net/projects/atftp/
COMMENT=		Advanced TFTP client and server

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/atftp ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/atftp.1 ${PREFIX}/man/man1
	${INSTALL_PROGRAM} ${WRKSRC}/atftpd ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/atftpd.8 ${PREFIX}/man/man8

.include "../../mk/bsd.pkg.mk"
