# $NetBSD: Makefile,v 1.4 2004/04/25 07:10:55 blef Exp $
#

DISTNAME=	ccze-0.2.1
CATEGORIES=	sysutils
MASTER_SITES=	ftp://bonehunter.rulez.org/pub/ccze/stable/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://bonehunter.rulez.org/CCZE.phtml
COMMENT=	Log coloriser, fast and light on resources

GNU_CONFIGURE=		yes
USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make

.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
