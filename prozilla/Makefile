# $NetBSD: Makefile,v 1.2 2004/06/21 15:57:13 ppostma Exp $
#

DISTNAME=		prozilla-1.3.6
CATEGORIES=		net
MASTER_SITES=		http://prozilla.genesys.ro/downloads/prozilla/tarballs/

MAINTAINER=	 	low@ameba6.com
HOMEPAGE=		http://www.gnu.org/directory/network/Tools/ProZilla.html
COMMENT=		ProZilla is a multi-threaded download accelerator.

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_GNU_TOOLS+=		make

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
