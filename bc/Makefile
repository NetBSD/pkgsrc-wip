# $NetBSD: Makefile,v 1.4 2003/08/29 10:31:21 thomasklausner Exp $

DISTNAME=	bc-1.06
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GNU:=bc/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/bc/bc.html
COMMENT=	Arbitrary precision calculator language
# this provides dc(1) which is essential for pkgsrc installations

USE_BUILDLINK2=	YES
GNU_CONFIGURE=	YES
INFO_FILES=	bc.info dc.info

.include "../../mk/bsd.prefs.mk"

.if !exists(/usr/bin/flex)
BUILD_DEPENDS+=	flex-*:../../devel/flex
.endif

.include "../../devel/ncurses/buildlink2.mk"
.include "../../devel/readline/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
