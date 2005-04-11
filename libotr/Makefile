# $NetBSD: Makefile,v 1.2 2005/04/11 21:13:48 tvierling Exp $

DISTNAME=	libotr-2.0.1
CATEGORIES=	devel
MASTER_SITES=	http://www.cypherpunks.ca/otr/

MAINTAINER=	gdt@ir.bbn.com
HOMEPAGE=	http://www.cypherpunks.ca/otr
COMMENT=	Library for private, deniable messaging

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

.include "../../security/libgpg-error/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
