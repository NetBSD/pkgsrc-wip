# $NetBSD$

DISTNAME=	kafkacat-1.6.0
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=edenhill/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/edenhill/kafkacat/
COMMENT=	Generic command line non-JVM Apache Kafka producer and consumer
LICENSE=	2-clause-bsd

CONFIG_SHELL=	bash
HAS_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	bash gmake pkg-config

CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--mandir=${PREFIX}/${PKGMANDIR}
CONFIGURE_ARGS+=	--enable-json
CONFIGURE_ARGS+=	--disable-avro

REPLACE_BASH+=	bootstrap.sh
REPLACE_BASH+=	configure
REPLACE_BASH+=	configure.self
REPLACE_BASH+=	mklove/modules/*

INSTALLATION_DIRS+=	${PKGMANDIR}/man1

post-install:
	${INSTALL_MAN} ${WRKSRC}/kafkacat.1 \
	    ${DESTDIR}/${PREFIX}/${PKGMANDIR}/man1

.include "../../devel/librdkafka/buildlink3.mk"
.include "../../devel/yajl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
