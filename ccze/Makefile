# $NetBSD: Makefile,v 1.1.1.1 2003/10/30 11:10:52 xtraeme Exp $
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
USE_NCURSES=		yes

.include "../../devel/ncurses/buildlink2.mk"
.include "../../devel/pcre/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
