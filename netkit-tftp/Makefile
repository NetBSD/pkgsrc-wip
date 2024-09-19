# $NetBSD: Makefile,v 1.6 2012/11/25 23:32:28 othyro Exp $

DISTNAME=		netkit-tftp-0.17
CATEGORIES=		net
#MASTER_SITES=		ftp://ftp.uk.linux.org/pub/linux/Networking/netkit/

MAINTAINER=		pkgsrc-users@NetBSD.org
#HOMEPAGE=		ftp://ftp.uk.linux.org/pub/linux/Networking/netkit/
COMMENT=		TFPD client and server from the Linux NetKIT

USE_PKGLOCALEDIR=	yes
HAS_CONFIGURE=		yes
ONLY_FOR_PLATFORM=	Linux-*-*

INSTALLATION_DIRS=	bin sbin ${PKGMANDIR}/man1 ${PKGMANDIR}/man8

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tftp/tftp ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/tftp/tftp.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/
	${INSTALL_PROGRAM} ${WRKSRC}/tftpd/tftpd ${DESTDIR}${PREFIX}/sbin/in.tftpd
	${INSTALL_MAN} ${WRKSRC}/tftpd/tftpd.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8/

.include "../../mk/bsd.pkg.mk"
