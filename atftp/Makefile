# $NetBSD: Makefile,v 1.5 2006/10/26 11:18:17 poppnk Exp $
#

DISTNAME=		atftp-0.7
PKGREVISION=		2
CATEGORIES=		net
MASTER_SITES=		ftp://ftp.mamalinux.com/pub/atftp/ \
			http://osmirrors.cerias.purdue.edu/pub/gentoo/distfiles/

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
