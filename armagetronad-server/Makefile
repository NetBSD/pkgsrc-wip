# $NetBSD: Makefile,v 1.3 2010/12/26 05:01:21 davesainty Exp $
#

.include "../../wip/armagetronad/Makefile.common"

PKGNAME=	${DISTNAME:S/.src//:S/armagetronad/armagetronad-server/}
COMMENT=	Server for the armagetronad game

MAINTAINER=     pkgsrc-users@NetBSD.org

# Enable server, don't build client
CONFIGURE_ARGS+=	--enable-dedicated

.include "../../mk/bsd.pkg.mk"
