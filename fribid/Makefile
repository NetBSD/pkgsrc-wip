# $NetBSD: Makefile,v 1.2 2012/09/28 23:21:49 asau Exp $

DISTNAME=		fribid-1.0.0
PKGNAME=		fribid-1.0.0
CATEGORIES=		security
MASTER_SITES=		http://fribid.se/releases/source/

MAINTAINER=		oht@users.sourceforge.net
HOMEPAGE=		http://fribid.se/
EXTRACT_SUFX=    	.tar.bz2
COMMENT=		FriBID  is a web browser plugin for BankID
USE_TOOLS+=             gmake pkg-config
LICENSE=		mit

PKG_DESTDIR_SUPPORT=    none

CONFIGURE_ARGS+=	--prefix=${PREFIX}  --mandir=${PKGMANDIR}
HAS_CONFIGURE=		yes


.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

