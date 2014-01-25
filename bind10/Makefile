# $NetBSD: Makefile,v 1.2 2014/01/25 10:38:09 thomasklausner Exp $
#
# TODO:
# CONF_FILES etc/bind10/cmdctl-accounts.csv
#etc/bind10/cmdctl-certfile.pem
#etc/bind10/cmdctl-keyfile.pem
# --localstatedir
# rc.d script
# Python readline module
# options for dhcp vs. dns

BIND_VERSION=	1.0.0-beta
DISTNAME=	bind10-${BIND_VERSION}
PKGNAME=	${DISTNAME:S/-beta/.beta/}
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.isc.org/isc/bind10/${BIND_VERSION}/

MAINTAINER=	jreed@isc.org
HOMEPAGE=	http://bind10.isc.org/
COMMENT=	ISC BIND 10 DNS and DHCP Suite
LICENSE=	isc

DEPENDS+=	${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3

GNU_CONFIGURE=	yes
USE_LANGUAGES+=	c++
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
PLIST_SUBST+=	PYSITELIB=${PYSITELIB:Q}
PYTHON_VERSIONS_INCOMPATIBLE=	26 27

PKG_INSTALLATION_TYPES=	overwrite pkgviews

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/log4cplus/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../security/botan/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
