# $NetBSD: Makefile,v 1.1.1.1 2005/06/03 17:07:00 poppnk Exp $
#

DISTNAME=		IoServer-2005-05-31
PKGNAME=		io-server-20050531
COMMENT=		Small Programming Language (vm + server addons)

CONFLICT+=		io-vm-[0-9]*
CONFLICT+=		io-desktop-[0-9]*

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/IoServer/ioServer ${PREFIX}/bin

.include "../../wip/io-vm/Makefile.common"

.include "../../mk/bsd.pkg.mk"
