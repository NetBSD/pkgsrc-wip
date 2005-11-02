# $NetBSD: Makefile,v 1.4 2005/11/02 18:00:08 thomasklausner Exp $
#

DISTNAME=		doorman-0.8
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=doorman/}
EXTRACT_SUFX=		.tgz

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://doorman.sourceforge.net/
COMMENT=			Open ports when requested by a *secret knock*

DEPENDS=	lsof>4.7:../../sysutils/lsof

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_TOOLS=		bison

.include "../../databases/db4/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../devel/flex/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
