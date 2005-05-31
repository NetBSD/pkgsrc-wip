# $NetBSD: Makefile,v 1.2 2005/05/31 12:10:47 poppnk Exp $
#

DISTNAME=		atftp-0.7
PKGREVISION=		1
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

.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
