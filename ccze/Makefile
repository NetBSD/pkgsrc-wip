# $NetBSD: Makefile,v 1.2 2003/12/28 00:39:17 thomasklausner Exp $
#

DISTNAME=	ccze-0.2.1
CATEGORIES=	sysutils
MASTER_SITES=	ftp://bonehunter.rulez.org/pub/ccze/stable/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://bonehunter.rulez.org/CCZE.phtml
COMMENT=	Log coloriser, fast and light on resources

GNU_CONFIGURE=		yes
USE_BUILDLINK2=		yes
USE_GMAKE=		yes

.include "../../devel/ncurses/buildlink2.mk"
.include "../../devel/pcre/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
