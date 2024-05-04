# $NetBSD: Makefile,v 1.8 2024/03/05 19:44:36 vins Exp $

DISTNAME=	libbsd-0.13.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=cheusov/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	cheusov@NetBSD.org
HOMEPAGE=	https://libbsd.freedesktop.org/
COMMENT=	Adapted for Solaris-10 libbsd
LICENSE=	modified-bsd AND 2-clause-bsd AND isc AND mit AND beer-ware

GIT_REPOSITORIES=	libbsd
GIT_REPO.libbsd=	https://github.com/cheusov/libbsd.git
GIT_BRANCH.libbsd=	main
.include "../../wip/mk/git-package.mk"

WRKSRC=		${WRKDIR}/libbsd

NOT_FOR_PLATFORM=	NetBSD-*-* FreeBSD-*-*
NOT_FOR_PLATFORM+=	OpenBSD-*-* DragonFly-*

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config autoconf automake autoreconf gmake

TEST_TARGET=	check

pre-configure:
	set -e; cd ${WRKSRC}; ./autogen

PKGCONFIG_OVERRIDE+=	src/libbsd-ctor.pc.in
PKGCONFIG_OVERRIDE+=	src/libbsd-overlay.pc.in
PKGCONFIG_OVERRIDE+=	src/libbsd.pc.in

.include "../../devel/libmd/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
