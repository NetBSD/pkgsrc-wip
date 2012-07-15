# $NetBSD: Makefile,v 1.1 2012/07/15 14:02:00 fhajny Exp $
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

PKG_DESTDIR_SUPPORT=	user-destdir

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
.include "../../lang/python/application.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
