# $NetBSD: Makefile,v 1.2 2005/04/11 21:14:51 tvierling Exp $
#

DISTNAME=		prothon-115
CATEGORIES=		lang
MASTER_SITES=		http://prothon.org/pub/prothon/

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://www.prothon.org/
COMMENT=		Classless prototype-based programming language

BUILD_DEPENDS+=		bison13>=1.35:../../wip/bison13

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_GNU_TOOLS+=		make

.include "../../devel/apr/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
