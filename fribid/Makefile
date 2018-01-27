# $NetBSD: Makefile,v 1.3 2012/11/23 22:33:35 othyro Exp $

DISTNAME=		fribid-1.0.0
PKGNAME=		fribid-1.0.0
CATEGORIES=		security
MASTER_SITES=		http://fribid.se/releases/source/

MAINTAINER=		oht@users.sourceforge.net
HOMEPAGE=		http://fribid.se/
EXTRACT_SUFX=		.tar.bz2
COMMENT=		FriBID  is a web browser plugin for BankID
USE_TOOLS+=		gmake pkg-config
LICENSE=		mit


CONFIGURE_ARGS+=	--prefix=${PREFIX}  --mandir=${PKGMANDIR}
HAS_CONFIGURE=		yes


.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
