# $NetBSD: Makefile,v 1.2 2004/05/12 13:14:18 thomasklausner Exp $
#

DISTNAME=	tls1.4
PKGNAME=	${DISTNAME:S/tls/tls-/}
CATEGORIES=	security
MASTER_SITES=	ftp://tcl.activestate.com/pub/tcl/tls/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.tcl.tk/
COMMENT=	TLS (aka SSL) Channel for the TCL language

USE_BUILDLINK3=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-ssl-dir=${BUILDLINK_PREFIX.openssl}
CONFIGURE_ENV+=		LOCALBASE=${LOCALBASE:Q}

.include "../../lang/tcl/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
