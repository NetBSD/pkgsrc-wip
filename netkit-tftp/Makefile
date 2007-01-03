# $NetBSD: Makefile,v 1.4 2007/01/03 14:38:16 shattered Exp $
#

DISTNAME=		netkit-tftp-0.17
CATEGORIES=		net
MASTER_SITES=		ftp://ftp.uk.linux.org/pub/linux/Networking/netkit/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		ftp://ftp.uk.linux.org/pub/linux/Networking/netkit/
COMMENT=		TFPD client and server from the Linux NetKIT

USE_PKGLOCALEDIR=	yes
HAS_CONFIGURE=		yes
ONLY_FOR_PLATFORM=	Linux-*-*

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tftp/tftp ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/tftp/tftp.1 ${PREFIX}/${PKGMANDIR}/man1/
	${INSTALL_PROGRAM} ${WRKSRC}/tftpd/tftpd ${PREFIX}/sbin/in.tftpd
	${INSTALL_MAN} ${WRKSRC}/tftpd/tftpd.8 ${PREFIX}/${PKGMANDIR}/man8/

.include "../../mk/bsd.pkg.mk"
