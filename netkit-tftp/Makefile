# $NetBSD: Makefile,v 1.1.1.1 2005/05/23 17:19:11 poppnk Exp $
#

DISTNAME=		netkit-tftp-0.17
CATEGORIES=		wip net
MASTER_SITES=		ftp://ftp.uk.linux.org/pub/linux/Networking/netkit/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		ftp://ftp.uk.linux.org/pub/linux/Networking/netkit/
COMMENT=		TFPD client and server from the Linux NetKIT

USE_PKGLOCALEDIR=	yes
HAS_CONFIGURE=		yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tftp/tftp ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/tftp/tftp.1 ${PREFIX}/man/man1/
	${INSTALL_PROGRAM} ${WRKSRC}/tftpd/tftpd ${PREFIX}/sbin/in.tftpd
	${INSTALL_MAN} ${WRKSRC}/tftpd/tftpd.8 ${PREFIX}/man/man8/

.include "../../mk/bsd.pkg.mk"
