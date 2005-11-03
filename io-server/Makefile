# $NetBSD: Makefile,v 1.2 2005/11/03 10:55:15 rillig Exp $
#

DISTNAME=		IoServer-2005-05-31
PKGNAME=		io-server-20050531
COMMENT=		Small Programming Language (vm + server addons)

CONFLICTS+=		io-vm-[0-9]*
CONFLICTS+=		io-desktop-[0-9]*

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/IoServer/ioServer ${PREFIX}/bin

.include "../../wip/io-vm/Makefile.common"

.include "../../mk/bsd.pkg.mk"
