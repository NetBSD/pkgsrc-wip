# $NetBSD: Makefile,v 1.1 2012/01/31 22:59:45 pettai Exp $
#

DISTNAME=	bind10-devel-20120119
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.isc.org/isc/bind10/devel-20120119/

MAINTAINER=	pettai@NetBSD.org
HOMEPAGE=	ftp://ftp.isc.org/isc/bind10/devel-20120119/
COMMENT=	ISC Bind 10 devel-20120119 (snapshot #19)
LICENSE=	isc

PKG_DESTDIR_SUPPORT=	user-destdir

PYTHON_VERSIONS_ACCEPTED= 31

PLIST_SUBST+=	PYSITELIB="${PYSITELIB}"

BUILD_DEFS+=	VARBASE

DEPENDS+=	${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++

#CONF_FILES=	etc/bind10-devel/cmdctl-accounts.csv \
#		share/example/bind10-devel/cmdctl-accounts.csv
#CONF_FILES+=	etc/bind10-devel/cmdctl-certfile.pem \
#		share/example/bind10-devel/cmdctl-certfile.pem
#CONF_FILES+=	etc/bind10-devel/cmdctl-keyfile.pem \
#		share/example/bind10-devel/cmdctl-keyfile.pem

.include "../../lang/python31/buildlink3.mk"
.include "../../security/botan/buildlink3.mk"
.include "../../devel/log4cplus/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
