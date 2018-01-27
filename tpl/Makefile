# $NetBSD$

DISTNAME=	tpl-1.6.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=troydhanson/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	angelmadames@gmail.com
HOMEPAGE=	https://github.com/troydhanson/tpl/
COMMENT=	Store and reload your C data
LICENSE=	2-clause-bsd

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	automake autoconf aclocal
USE_LANGUAGES=	c c++

pre-configure:
	set -x; cd ${WRKSRC}; autoreconf -fiv

.include "../../mk/bsd.pkg.mk"
