# $NetBSD$

# Libreswan is built using GNU Make.  It does not use autoconf.
#
# Configuration parameters can be found in mk/config.mk and OS
# specific overides in mk/default/*.mk (for instance,
# mk/default/netbsd.mk).

DISTNAME=	libreswan-4.7
CATEGORIES=	security
MASTER_SITES=	https://download.libreswan.org/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://libreswan.org/
# Libreswan is an ...
COMMENT=	Internet Key Exchange Daemon for managing IPsec
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	pkg-config
USE_TOOLS+=	gmake
USE_TOOLS+=	flex
USE_TOOLS+=	bison
#default is: USE_LANGUAGES+=	c

DEPENDS+=	xmlto-[0-9]*:../../textproc/xmlto
# weak dependency
#DEPENDS+=	logrotate-[0-9]*:../../sysutils/logrotate

CHECK_PORTABILITY_SKIP=	mk/docker-targets.mk

# code not clean enough
BUILDLINK_TRANSFORM+=	rm:-Werror

MAKE_FLAGS+=	PYTHON_BINARY=${PYTHONBIN}

# libevent?
.include "../../net/unbound/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../devel/nss/buildlink3.mk"
.include "../../net/ldns/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
