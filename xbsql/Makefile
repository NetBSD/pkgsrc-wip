# $NetBSD: Makefile,v 1.4 2004/04/13 20:56:41 blef Exp $
#

DISTNAME=		xbsql-0.11
CATEGORIES=		wip
MASTER_SITES=		http://www.rekallrevealed.org/packages/
EXTRACT_SUFX=		.tgz

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://www.rekallrevealed.org/packages/
COMMENT=		SQL frontend for DB4 (DBF) files with xbase

BUILD_DEPENDS+=		bison-[0-9]*:../../devel/bison

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

.include "../../wip/xbase/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
