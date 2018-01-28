# $NetBSD$

VERSION=	2.16
PKGREVISION=	1
DISTNAME=	remctl-${VERSION}
PKGNAME=	${PYPKGPREFIX}-remctl-${VERSION}
CATEGORIES=	sysutils security
MASTER_SITES=	http://archives.eyrie.org/software/kerberos/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.eyrie.org/~eagle/software/remctl/
COMMENT=	Python bindings for remctl remote command execution
LICENSE=	mit

USE_LIBTOOL=		yes
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--enable-gssapi=${KRB5BASE}
CONFIGURE_ARGS+=	--with-gss_impl=${GSSIMPL.${KRB5_TYPE}}
GSSIMPL.heimdal=	heimdal
GSSIMPL.mit-krb5=	mit

CONFIGURE_ARGS+=	--enable-python

BUILDLINK_API_DEPENDS.heimdal+=	heimdal>=0.7
BUILDLINK_API_DEPENDS.remctl+=	remctl>=${PKGVERSION}

PYDISTUTILSPKG=	yes
PYSETUPSUBDIR=	python

.include "../../lang/python/extension.mk"
.include "../../wip/remctl/buildlink3.mk"
.include "../../mk/krb5.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
