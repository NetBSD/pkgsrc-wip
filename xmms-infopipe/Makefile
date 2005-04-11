# $NetBSD: Makefile,v 1.6 2005/04/11 21:16:18 tvierling Exp $
#

DISTNAME=		xmms-infopipe-1.3
CATEGORIES=		audio
MASTER_SITES=		http://www.beastwithin.org/users/wwwwolf/code/xmms/

MAINTAINER=		ivaniclixx@gmail.com
HOMEPAGE=		http://www.beastwithin.org/users/wwwwolf/code/xmms/infopipe.html
COMMENT=		Plugin that reports XMMS status via named pipe

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
GNU_CONFIGURE=		yes

.include "../../audio/xmms/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
