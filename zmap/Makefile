# $NetBSD: Makefile,v 1.3 2015/01/20 12:02:10 ahp-nils Exp $

DISTNAME=	zmap-4.4.0
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=zmap/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://zmap.io/
COMMENT=	Network scanner that scales to Internet-wide network studies
LICENSE=	apache-2.0

TOOL_DEPENDS+=	gengetopt-[0-9]*:../../devel/gengetopt

USE_TOOLS+=	byacc pkg-config

CMAKE_CONFIGURE_ARGS=	-DRESPECT_INSTALL_PREFIX_CONFIG=ON

.include "../../devel/cmake/build.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../net/libdnet/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../textproc/json-c/buildlink3.mk"
.include "../../textproc/libunistring/buildlink3.mk"
.include "../../wip/judy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
