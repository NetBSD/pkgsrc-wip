# $NetBSD: Makefile,v 1.4 2012/10/07 14:53:44 asau Exp $
#

DISTNAME=		rte-0.5.6
CATEGORIES=		multimedia
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=zapping/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://zapping.sourceforge.net/Zapping/
COMMENT=		Real Time Audio/Video Encoding Library


USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
