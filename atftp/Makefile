# $NetBSD: Makefile,v 1.4 2006/04/20 13:36:35 cheusov Exp $
#

DISTNAME=		atftp-0.7
PKGREVISION=		1
CATEGORIES=		net
MASTER_SITES=		ftp://ftp.mamalinux.com/pub/atftp/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://freshmeat.net/projects/atftp/
COMMENT=		Advanced TFTP client and server

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/atftp ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/atftp.1 ${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_PROGRAM} ${WRKSRC}/atftpd ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/atftpd.8 ${PREFIX}/${PKGMANDIR}/man8

.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
