# $NetBSD: Makefile,v 1.6 2012/09/29 00:50:41 asau Exp $
#

DISTNAME=		guilerxspencer-1.2
PKGREVISION=		1
CATEGORIES=		devel
MASTER_SITES=		http://www.arglist.com/guile/${DISTNAME}/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.arglist.com/guile/
COMMENT=		Guile bindings for Henry Spencer's regex

PKG_DESTDIR_SUPPORT=	none

GNU_CONFIGURE=		yes
INSTALLATION_DIRS=	share/guile/site

.include "../../lang/guile/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
