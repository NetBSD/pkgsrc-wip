# $NetBSD: Makefile,v 1.2 2004/12/02 16:39:00 thomasklausner Exp $
#

DISTNAME=		ispell-lt-1.0
PKGNAME=		ispell-lietuviu-1.0
CATEGORIES=		textproc
MASTER_SITES=		ftp://ftp.akl.lt/ispell-lt/

MAINTAINER=		tomas.furmonavicius@takas.lt
HOMEPAGE=		http://www.lietuvybe.org/?menuid=Zodynai&submenu=ispell-lt
COMMENT=	 	Lithuanian dictionary for ispell

BUILD_DEPENDS+=		python23-[0-9]*:../../lang/python23
DEPENDS+=		ispell-base-[0-9]*:../../textproc/ispell-base

BUILD_TARGET=		lietuviu.hash
USE_BUILDLINK3=		yes

.include "../../mk/bsd.pkg.mk"
