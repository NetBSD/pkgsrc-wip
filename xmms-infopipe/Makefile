# $NetBSD: Makefile,v 1.2 2004/07/18 15:01:34 ppostma Exp $
#

DISTNAME=		xmms-infopipe-1.3
CATEGORIES=		audio
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
