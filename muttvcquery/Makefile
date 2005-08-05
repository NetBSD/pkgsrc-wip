# $NetBSD: Makefile,v 1.1.1.1 2005/08/05 21:08:27 poppnk Exp $
#

DISTNAME=		mutt_vc_query-002
PKGNAME=		muttvcquery-002
CATEGORIES=		wip mail
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=rolo/}

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://rolo.sourceforge.net/
COMMENT=		External contact manager for mutt

DEPENDS+=		rolo-[0-9]*:../../wip/rolo

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

.include "../../wip/libvc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
