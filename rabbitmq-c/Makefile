# $NetBSD: Makefile,v 1.4 2013/02/25 15:26:07 fhajny Exp $
#

DISTNAME=	rabbitmq-c-v0.3.0
PKGNAME=	${DISTNAME:S/c-v/c-/}
CATEGORIES=	net
MASTER_SITES=	https://github.com/alanxz/rabbitmq-c/archive/
FETCH_USING=	curl

MAINTAINER=	filip@joyent.com
HOMEPAGE=	https://github.com/alanxz/rabbitmq-c
COMMENT=	C-language AMQP client library for use with AMQP servers
LICENSE=	mit

WRKSRC=			${WRKDIR}/${PKGBASE}-${DISTNAME}

USE_CMAKE=		yes
USE_LANGUAGES+=		c99
USE_TOOLS+=		pkg-config

# Needed for docs and man pages - doesn't work now
# BUILD_DEPENDS+=	xmlto-[0-9]*:../../textproc/xmlto
# CMAKE_ARGS+=		-DBUILD_TOOLS_DOC=on

CMAKE_ARGS+=		-DBUILD_TOOLS=ON

CFLAGS.SunOS+=		-DHAVE_HTONLL=1

.include "../../devel/popt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
