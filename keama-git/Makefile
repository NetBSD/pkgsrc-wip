# $NetBSD$

PKGNAME=	keama-0.0
CATEGORIES=	net
GIT_REPO=	https://gitlab.isc.org/isc-projects/dhcp.git
GIT_ENV=	GIT_SSL_NO_VERIFY=true

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.isc.org/kea/
COMMENT=	Migration tool from ISC dhcp to kea dhcp
LICENSE=	mpl-2.0

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++
BUILD_DIRS=	keama
USE_TOOLS=	autoconf

pre-configure:
	cd ${WRKSRC} && autoconf


.include "../../wip/mk/git-package.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
