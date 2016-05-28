# $NetBSD: Makefile,v 1.14 2012/11/25 23:32:30 othyro Exp $
#

DISTNAME=		rolo-011
CATEGORIES=		mail
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=rolo/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://rolo.sourceforge.net/
COMMENT=		Text-based contact manager


USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

.include "../../devel/ncurses/buildlink3.mk"
.include "../../wip/libvc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
