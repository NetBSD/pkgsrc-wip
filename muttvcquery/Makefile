# $NetBSD: Makefile,v 1.3 2012/10/03 15:10:00 asau Exp $
#

DISTNAME=		mutt_vc_query-002
PKGNAME=		muttvcquery-002
CATEGORIES=		mail
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=rolo/}

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://rolo.sourceforge.net/
COMMENT=		External contact manager for mutt

DEPENDS+=		rolo-[0-9]*:../../wip/rolo

PKG_DESTDIR_SUPPORT=	none

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

.include "../../wip/libvc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
