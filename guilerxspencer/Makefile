# $NetBSD: Makefile,v 1.1.1.1 2004/11/06 14:31:58 bencollver Exp $
#

DISTNAME=		guilerxspencer-1.2
CATEGORIES=		devel
MASTER_SITES=		http://arglist.com/guile/${DISTNAME}/

MAINTAINER=		ben@NetBSD.org
HOMEPAGE=		http://arglist.com/guile/
COMMENT=		Guile bindings for Henry Spencer's regex

USE_BUILDLINK3=		yes
GNU_CONFIGURE=		yes
INSTALLATION_DIRS=	share/guile/site

.include "../../lang/guile/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
