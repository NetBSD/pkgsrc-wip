# $NetBSD: Makefile,v 1.1.1.1 2005/07/24 23:47:11 thomasklausner Exp $
#

DISTNAME=		rte-0.5.6
CATEGORIES=		multimedia
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=zapping/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://zapping.sourceforge.net/
COMMENT=		Real Time Audio/Video Encoding Library

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
