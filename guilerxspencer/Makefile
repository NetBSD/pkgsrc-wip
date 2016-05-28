# $NetBSD: Makefile,v 1.7 2012/11/13 19:33:45 othyro Exp $
#

DISTNAME=		guilerxspencer-1.2
PKGREVISION=		1
CATEGORIES=		devel
MASTER_SITES=		http://www.arglist.com/guile/${DISTNAME}/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.arglist.com/guile/
COMMENT=		Guile bindings for Henry Spencer's regex


GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
INSTALLATION_DIRS=	share/guile/site

.include "../../lang/guile/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
