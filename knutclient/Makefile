# $NetBSD: Makefile,v 1.3 2008/01/18 04:30:15 tnn2 Exp $
#

DISTNAME=		knutclient-0.9.3
PKGREVISION=		1
CATEGORIES=		sysutils kde
MASTER_SITES=		ftp://ftp.buzuluk.cz/pub/alo/knutclient/stable/

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX}

MAINTAINER=		jdw-pkgsrc@menelos.com
HOMEPAGE=		http://www.knut.noveradsl.cz/knutclient/
COMMENT=		KDE Client for NUT

USE_LANGUAGES=               c++

.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
