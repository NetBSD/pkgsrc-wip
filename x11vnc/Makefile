# $NetBSD: Makefile,v 1.1.1.1 2005/04/08 12:40:25 obache Exp $
#

DISTNAME=	x11vnc-0.7.1
CATEGORIES=	graphics x11
MASTER_SITES=   ${MASTER_SITE_SOURCEFORGE:=libvncserver/}

MAINTAINER=	obata@lins.jp
HOMEPAGE=	http://www.karlrunge.com/x11vnc/
COMMENT=	VNC server for real X displays

USE_X11=		yes
GNU_CONFIGURE=		yes

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
