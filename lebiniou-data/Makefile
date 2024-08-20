# $NetBSD$

DISTNAME=	lebiniou-data-version-3.66.0
PKGNAME=	lebiniou-data-3.66.0
CATEGORIES=	multimedia
MASTER_SITES=	https://gitlab.com/lebiniou/lebiniou-data/-/archive/version-3.66.0/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://biniou.net/
COMMENT=	Datafiles for Le Biniou
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	autoconf automake autoreconf bash
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes

pre-configure:
	set -e; cd ${WRKSRC} && ./bootstrap

.include "../../mk/bsd.pkg.mk"
