# $NetBSD: Makefile,v 1.9 2012/10/05 11:31:52 asau Exp $
#

DISTNAME=	pidgin-sipe-1.11.2
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=sipe/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	yacht@users.sourceforge.net
HOMEPAGE=	http://sipe.sourceforge.net/
COMMENT=	Pidgin plugin for Microsoft Office Communicator

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	intltool pkg-config

BUILDLINK_TRANSFORM+=	rm:-Werror

.include "../../chat/libpurple/buildlink3.mk"
.include "../../devel/libidn/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
