# $NetBSD: Makefile,v 1.3 2005/01/20 19:39:47 ppostma Exp $
#

DISTNAME=		tls1.5.0-src
PKGNAME=		tls-1.5.0
CATEGORIES=		security
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=tls/}

MAINTAINER=		peter@pointless.nl
HOMEPAGE=		http://www.tcl.tk/
COMMENT=		TLS (aka SSL) Channel for the Tcl language

WRKSRC=			${WRKDIR}/tls1.5

USE_BUILDLINK3=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-ssl-dir=${BUILDLINK_PREFIX.openssl}
CONFIGURE_ENV+=		LOCALBASE=${LOCALBASE:Q}

.include "../../lang/tcl/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
