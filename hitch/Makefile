# $NetBSD$

DISTNAME=	hitch-1.2.0
CATEGORIES=	security
MASTER_SITES=	https://hitch-tls.org/source/

MAINTAINER=	filip@joyent.com
HOMEPAGE=	https://hitch-tls.org/
COMMENT=	Scalable TLS proxy
LICENSE=	2-clause-bsd

BUILD_DEPENDS+=	${PYPKGPREFIX}-docutils-[0-9]*:../../textproc/py-docutils

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config

CONFIGURE_ARGS+=	--with-rst2man=${PREFIX}/bin/rst2man.py${PYVERSSUFFIX}

CPPFLAGS.SunOS+=	-D__EXTENSIONS__
LIBS.SunOS+=		-lsocket

INSTALLATION_DIRS+=	share/examples/hitch

PKG_SYSCONFSUBDIR=	hitch

CONF_FILES+=		share/examples/hitch/hitch.conf.ex \
			${PKG_SYSCONFDIR}/hitch.conf

post-install:
	${MV} ${DESTDIR}${PREFIX}/share/doc/hitch/hitch.conf.ex \
		${DESTDIR}${PREFIX}/share/examples/hitch

PYTHON_FOR_BUILD_ONLY=	yes
.include "../../lang/python/pyversion.mk"

.include "../../devel/libev/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
