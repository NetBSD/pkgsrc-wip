# $NetBSD$

GITHUB_PROJECT=	libfixposix
GITHUB_TAG=	v0.4.3
DISTNAME=	v0.4.3
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=sionescu/}
DIST_SUBDIR=	${GITHUB_PROJECT}

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
