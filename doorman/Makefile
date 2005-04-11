# $NetBSD: Makefile,v 1.2 2005/04/11 21:11:34 tvierling Exp $
#

DISTNAME=		doorman-0.8
CATEGORIES=		wip
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=doorman/}
EXTRACT_SUFX=		.tgz

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://doorman.sourceforge.net/
COMMENT=			Open ports when requested by a *secret knock*

DEPENDS=	lsof>4.7:../../sysutils/lsof

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_GNU_TOOLS=yacc

.include "../../databases/db4/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../devel/flex/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
