# $NetBSD: Makefile,v 1.1.1.1 2003/05/17 19:08:42 jeremy-c-reed Exp $

DISTNAME=	bc-1.06
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GNU:=bc/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/bc/bc.html
COMMENT=	arbitrary precision calculator language
# this provides dc(1) which is essential for pkgsrc installations

USE_BUILDLINK2=	YES
GNU_CONFIGURE=	YES

.include "../../mk/bsd.prefs.mk"

.if !exists(/usr/bin/flex)
BUILD_DEPENDS+=	flex-*:../../devel/flex
.endif

.include "../../devel/ncurses/buildlink2.mk"
.include "../../devel/readline/buildlink2.mk"
.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
