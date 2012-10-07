# $NetBSD: Makefile,v 1.13 2012/10/07 14:53:43 asau Exp $
#

DISTNAME=		rolo-011
CATEGORIES=		mail
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=rolo/}

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://rolo.sourceforge.net/
COMMENT=		Text-based contact manager

PKG_DESTDIR_SUPPORT=	none

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

.include "../../devel/ncurses/buildlink3.mk"
.include "../../wip/libvc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
