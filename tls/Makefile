# $NetBSD: Makefile,v 1.1.1.1 2003/10/30 23:47:51 xtraeme Exp $
#

DISTNAME=	tls1.4
PKGNAME=	${DISTNAME:S/tls/tls-/}
CATEGORIES=	security
MASTER_SITES=	ftp://tcl.activestate.com/pub/tcl/tls/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.tcl.tk/
COMMENT=	TLS (aka SSL) Channel for the TCL language

USE_BUILDLINK2=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-ssl-dir=${BUILDLINK_PREFIX.openssl}

.include "../../lang/tcl/buildlink2.mk"
.include "../../security/openssl/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
