# $NetBSD: Makefile,v 1.3 2012/10/07 14:53:42 asau Exp $
#

DISTNAME=	rabbitmq-c
PKGNAME=	${DISTNAME}-0.2${GIT_TAG}
CATEGORIES=	net

MAINTAINER=	filip@joyent.com
HOMEPAGE=	https://github.com/alanxz/rabbitmq-c
COMMENT=	C-language AMQP client library for use with AMQP servers
LICENSE=	mit

GIT_REPOSITORIES=	rabbitmq-c
GIT_REPO.rabbitmq-c=	git://github.com/alanxz/rabbitmq-c.git

USE_LIBTOOL=		yes
USE_TOOLS+=		autoconf automake autoreconf gmake perl pkg-config
HAS_CONFIGURE=		yes

BUILD_DEPENDS+=		${PYPKGPREFIX}-simplejson-[0-9]*:../../converters/py-simplejson
BUILD_DEPENDS+=		xmlto-[0-9]*:../../textproc/xmlto

CONFIGURE_ENV+=		LIBS=${LIBS:Q}
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--mandir=${PREFIX}/${PKGMANDIR}

LIBS.SunOS+=		-lsocket

pre-configure:
	cd ${WRKSRC} && autoreconf -i

.include "../../wip/mk/git-package.mk"
# Init and update submodules too
_GIT_FLAGS+=		--recursive

.include "../../lang/python/application.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
