# $NetBSD: Makefile,v 1.1.1.1 2004/03/27 23:54:25 mpasternak Exp $
#

DISTNAME=		prothon-115
CATEGORIES=		lang
MASTER_SITES=		http://prothon.org/pub/prothon/

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://www.prothon.org/
COMMENT=		Classless prototype-based programming language

BUILD_DEPENDS+=		bison13>=1.35:../../wip/bison13

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_GNU_TOOLS+=		make

.include "../../devel/apr/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
