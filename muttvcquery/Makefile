# $NetBSD: Makefile,v 1.4 2012/11/25 23:32:28 othyro Exp $
#

DISTNAME=		mutt_vc_query-002
PKGNAME=		muttvcquery-002
CATEGORIES=		mail
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=rolo/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://rolo.sourceforge.net/
COMMENT=		External contact manager for mutt

DEPENDS+=		rolo-[0-9]*:../../wip/rolo


USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

.include "../../wip/libvc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
