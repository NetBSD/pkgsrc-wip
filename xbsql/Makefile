# $NetBSD: Makefile,v 1.7 2004/09/23 06:00:05 jlamwww Exp $
#

DISTNAME=		xbsql-0.11
CATEGORIES=		database
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
