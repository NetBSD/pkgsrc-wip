# $NetBSD: Makefile,v 1.2 2012/10/07 14:53:43 asau Exp $
#

DISTNAME=	resin-4.0.8
CATEGORIES=	www
MASTER_SITES=	http://www.caucho.com/download/
EXTRACT_SUFX=	.zip

MAINTAINER=	tnn@NetBSD.org
HOMEPAGE=	http://www.caucho.com/
COMMENT=	High-performance, open source application server
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_JAVA=	yes
USE_LANGUAGES=	c c++

CFLAGS+=	-fPIC

CONFIGURE_ARGS+=	--enable-jni --enable-ssl
CONFIGURE_ARGS+=	--with-resin-root=${PREFIX}/resin/root
CONFIGURE_ARGS+=	--with-resin-log=${PREFIX}/resin/log
CONFIGURE_ARGS+=	--with-resin-conf=${PREFIX}/resin/conf

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
