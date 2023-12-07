# $NetBSD$

DISTNAME=	libnsl-2.0.1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=thkukuk/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/thkukuk/libnsl/
COMMENT=	Library for nis(yp) ans nis+
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gettext pkg-config

ONLY_FOR_PLATFORM=	Linux-*-*

PKGCONFIG_OVERRIDE=	libnsl.pc.in

.include "../../devel/libtirpc/buildlink3.mk"
.include "../../mk/krb5.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
