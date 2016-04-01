# $NetBSD$

DISTNAME=	hitch-1.1.1
CATEGORIES=	security
MASTER_SITES=	https://hitch-tls.org/source/

MAINTAINER=	filip@joyent.com
HOMEPAGE=	https://hitch-tls.org/
COMMENT=	Scalable TLS proxy
LICENSE=	2-clause-bsd

BUILD_DEPENDS+=	${PYPKGPREFIX}-docutils-[0-9]*:../../textproc/py-docutils

GNU_CONFIGURE=	yes

CPPFLAGS.SunOS+=	-D__EXTENSIONS__
LIBS.SunOS+=		-lsocket

PYTHON_FOR_BUILD_ONLY=	yes
.include "../../lang/python/pyversion.mk"

.include "../../devel/libev/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
