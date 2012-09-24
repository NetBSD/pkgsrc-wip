# $NetBSD: Makefile,v 1.9 2012/09/24 16:56:39 asau Exp $
#

DISTNAME=		atftp-0.7
PKGREVISION=		3
CATEGORIES=		net
MASTER_SITES=		ftp://ftp.mamalinux.com/pub/atftp/ \
			http://osmirrors.cerias.purdue.edu/pub/gentoo/distfiles/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://freshmeat.net/projects/atftp/
COMMENT=		Advanced TFTP client and server

ONLY_FOR_PLATFORM=	Linux-*-*

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes


do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/atftp ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/atftp.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_PROGRAM} ${WRKSRC}/atftpd ${DESTDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/atftpd.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8

.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
