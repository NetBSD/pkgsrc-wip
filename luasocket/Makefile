# $NetBSD: Makefile,v 1.2 2004/01/25 02:32:43 grantbeattie Exp $
#

DISTNAME=		luasocket-2.0-alpha
PKGNAME=		luasocket-2.0alpha
CATEGORIES=		wip
MASTER_SITES=		http://www.tecgraf.puc-rio.br/~diego/luasocket/new/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.tecgraf.puc-rio.br/~diego/luasocket/new/
COMMENT=		Gives socket capabilities to lua50

MAKEFILE=		${WRKSRC}/makefile
ALL_TARGET=		dyn
USE_GNU_TOOLS+=		make
USE_BUILDLINK2=		YES

.include "../../lang/lua/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
