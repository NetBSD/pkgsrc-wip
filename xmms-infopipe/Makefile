# $NetBSD: Makefile,v 1.1.1.1 2004/04/02 12:16:29 ivaniclixx Exp $
#

DISTNAME=		xmms-infopipe-1.3
CATEGORIES=		wip
MASTER_SITES=		http://www.beastwithin.org/users/wwwwolf/code/xmms/

MAINTAINER=		ivaniclixx@terra.es
HOMEPAGE=		http://www.beastwithin.org/users/wwwwolf/code/xmms/
COMMENT=		Plugin that reports XMMS status via named pipe

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
GNU_CONFIGURE=		yes

.include "../../audio/xmms/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
