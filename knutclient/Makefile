# $NetBSD: Makefile,v 1.1.1.1 2007/11/12 03:15:00 jdwhite Exp $
#

DISTNAME=		knutclient-0.9.3
CATEGORIES=		sysutils kde
MASTER_SITES=		ftp://ftp.buzuluk.cz/pub/alo/knutclient/stable/

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX}

MAINTAINER=		jdw-pkgsrc@menelos.com
HOMEPAGE=		http://www.knut.noveradsl.cz/knutclient/
COMMENT=		KDE Client for NUT

.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
