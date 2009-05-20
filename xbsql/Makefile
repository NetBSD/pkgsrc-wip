# $NetBSD: Makefile,v 1.13 2009/05/20 00:58:43 thomasklausner Exp $
#

DISTNAME=		xbsql-0.11
PKGREVISION=		1
CATEGORIES=		databases
MASTER_SITES=		http://www.rekallrevealed.org/packages/
EXTRACT_SUFX=		.tgz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.rekallrevealed.org/packages/
COMMENT=		SQL frontend for DB4 (DBF) files with xbase

BUILD_DEPENDS+=		bison-[0-9]*:../../devel/bison

USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

.include "../../wip/xbase/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
