# $NetBSD: Makefile,v 1.6 2014/01/25 10:38:09 thomasklausner Exp $

DISTNAME=	bind10-devel-20120329
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.isc.org/isc/bind10/devel-20120329/

MAINTAINER=	pettai@NetBSD.org
HOMEPAGE=	http://www.isc.org/bind10
COMMENT=	ISC Bind 10 devel-20120119 (snapshot #19)
LICENSE=	isc

PLIST_SUBST+=	PYSITELIB="${PYSITELIB}"

BUILD_DEFS+=	VARBASE

DEPENDS+=	${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}
USE_TOOLS+=	pkg-config
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++

#CONF_FILES=	etc/bind10-devel/cmdctl-accounts.csv \
#		share/example/bind10-devel/cmdctl-accounts.csv
#CONF_FILES+=	etc/bind10-devel/cmdctl-certfile.pem \
#		share/example/bind10-devel/cmdctl-certfile.pem
#CONF_FILES+=	etc/bind10-devel/cmdctl-keyfile.pem \
#		share/example/bind10-devel/cmdctl-keyfile.pem

.include "../../security/botan/buildlink3.mk"
.include "../../devel/log4cplus/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
