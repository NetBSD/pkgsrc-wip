# $NetBSD: Makefile,v 1.5 2010/01/20 14:04:59 thomasklausner Exp $
#

DISTNAME=	pidgin-sipe-1.7.1
PKGREVISION=	1
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=sipe/}

MAINTAINER=	yacht@users.sourceforge.net
HOMEPAGE=	http://sipe.sourceforge.net/
COMMENT=	Pidgin plugin for Microsoft Office Communicator

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	intltool pkg-config

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../chat/libpurple/buildlink3.mk"
.include "../../devel/libidn/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
