# $NetBSD: Makefile,v 1.1.1.1 2009/08/31 12:09:50 yacht Exp $
#

DISTNAME=	pidgin-sipe-1.6.2
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=sipe/}

MAINTAINER=	joachim.kuebart@gmx.net
HOMEPAGE=	http://sipe.sourceforge.net/
COMMENT=	Pidgin plugin for Microsoft Office Communicator

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	intltool pkg-config

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../chat/libpurple/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
