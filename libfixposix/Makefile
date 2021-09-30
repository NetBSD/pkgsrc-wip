# $NetBSD$

DISTNAME=	libfixposix-0.5.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=sionescu/}
GITHUB_TAG=	040cd8fba91e7bec8a14236db9f318c70f8c5390

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/sionescu/libfixposix/
COMMENT=	Thin wrapper over POSIX syscalls
LICENSE=	boost-license

USE_TOOLS+=	pkg-config autoconf automake
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes

pre-configure:
	cd ${WRKSRC} && autoreconf -fiv

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
