# $NetBSD: Makefile,v 1.3 2004/08/17 18:33:13 tvierling Exp $
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
LIBTOOL_LA_FILES+=	lib/xmms/General/libinfopipe.la
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
GNU_CONFIGURE=		yes

.include "../../audio/xmms/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
