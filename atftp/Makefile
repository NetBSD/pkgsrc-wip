# $NetBSD: Makefile,v 1.6 2008/03/01 14:27:22 asau Exp $
#

DISTNAME=		atftp-0.7
PKGREVISION=		2
CATEGORIES=		net
MASTER_SITES=		ftp://ftp.mamalinux.com/pub/atftp/ \
			http://osmirrors.cerias.purdue.edu/pub/gentoo/distfiles/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://freshmeat.net/projects/atftp/
COMMENT=		Advanced TFTP client and server

PKG_DESTDIR_SUPPORT=	user-destdir

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/atftp ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/atftp.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_PROGRAM} ${WRKSRC}/atftpd ${DESTDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/atftpd.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8

.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
