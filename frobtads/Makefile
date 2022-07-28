# $NetBSD: Makefile,v 1.1 2015/08/17 21:11:24 yhardy Exp $

DISTNAME=	frobtads-2.0
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=realnc/frobtads/releases/download/v2.0/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.tads.org/
COMMENT=	Portable TADS toolkit
#LICENSE=	tads3

USE_CMAKE=	YES
USE_LANGUAGES=	c c++14

.include "../../devel/ncurses/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
