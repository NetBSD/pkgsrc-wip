# $NetBSD: Makefile,v 1.12 2006/08/25 20:37:19 dhowland Exp $
#

DISTNAME=		rolo-011
CATEGORIES=		mail
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=rolo/}

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://rolo.sourceforge.net/
COMMENT=		Text-based contact manager

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

.include "../../devel/ncurses/buildlink3.mk"
.include "../../wip/libvc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
