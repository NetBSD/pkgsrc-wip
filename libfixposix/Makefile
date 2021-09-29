# $NetBSD$

DISTNAME=	libfixposix-0.4.3
PKGNAME=	${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=sionescu/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/sionescu/libfixposix/
COMMENT=	Thin wrapper over POSIX syscalls
LICENSE=	boost-license

USE_TOOLS+=	pkg-config autoreconf autoconf automake intltool autoupdate m4
GNU_CONFIGURE=	yes

WRKSRC=		${WRKDIR}/libfixposix-0.4.3

pre-configure:
	cd ${WRKSRC} && autoreconf -fiv

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
