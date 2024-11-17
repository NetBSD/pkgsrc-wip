# $NetBSD$

DISTNAME=	apk-tools-v3.0.0_pre0nb2
PKGNAME=	${DISTNAME:S,-v,-,}
CATEGORIES=	misc
MASTER_SITES=	https://nishi.boats/

MAINTAINER=	nishi@nishi.boats
HOMEPAGE=	https://git.alpinelinux.org/apk-tools/
COMMENT=	Alpine Package Keeper Tools
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/apk-tools

PATCHDIR=	../../misc/apk-tools/patches

DEPENDS+=	pkgconf>=0:../../devel/pkgconf
DEPENDS+=	meson>=0:../../devel/meson
DEPENDS+=	lua53>=0:../../lang/lua53

PKGCONFIG_OVERRIDE+=	src/apk.pc.in

.include "../../devel/meson/build.mk"
.include "../../mk/bsd.pkg.mk"
