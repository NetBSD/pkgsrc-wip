# $NetBSD: Makefile,v 1.5 2010/02/05 21:36:22 jakllsch Exp $

VERSION=	2.15
DISTNAME=	remctl-${VERSION}
CATEGORIES=	sysutils security
MASTER_SITES=	http://archives.eyrie.org/software/kerberos/

MAINTAINER=	jakllsch@NetBSD.org
HOMEPAGE=	http://www.eyrie.org/~eagle/software/remctl/
COMMENT=	Client/server protocol for running commands using Kerberos v5 auth

USE_LIBTOOL=		yes
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--enable-shared
CONFIGURE_ARGS+=	--enable-gssapi=${KRB5BASE:Q}
CONFIGURE_ARGS+=	--with-gss_impl=${GSSIMPL.${KRB5_TYPE}}
GSSIMPL.heimdal=	heimdal
GSSIMPL.mit-krb5=	mit

BUILDLINK_API_DEPENDS.heimdal+=	heimdal>=0.7

.include "../../mk/krb5.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
