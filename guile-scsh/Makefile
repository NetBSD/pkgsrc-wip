# $NetBSD: Makefile,v 1.1.1.1 2004/11/06 14:32:53 bencollver Exp $
#

DISTNAME=		guile-scsh-2.0.1
CATEGORIES=		shells
MASTER_SITES=		http://arglist.com/guile/${DISTNAME}/

MAINTAINER=		ben@NetBSD.org
HOMEPAGE=		http://arglist.com/guile/
COMMENT=		Scheme Shell that runs in Guile

USE_BUILDLINK3=		yes
GNU_CONFIGURE=		yes

.include "../../lang/guile/buildlink3.mk"
.include "../../wip/guilerxspencer/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
