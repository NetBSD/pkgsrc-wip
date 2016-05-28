# $NetBSD: Makefile,v 1.7 2012/10/01 21:57:40 asau Exp $
#

DISTNAME=		knutclient-0.9.3
PKGREVISION=		4
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
