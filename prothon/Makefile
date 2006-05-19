# $NetBSD: Makefile,v 1.5 2006/05/19 16:51:30 ykomatsu Exp $
#

DISTNAME=		prothon-115
CATEGORIES=		lang
MASTER_SITES=		http://prothon.org/pub/prothon/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.prothon.org/
COMMENT=		Classless prototype-based programming language

BUILD_DEPENDS+=		bison13>=1.35:../../wip/bison13

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake

.include "../../devel/apr/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
