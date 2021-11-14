# $NetBSD: Makefile,v 1.4 2012/10/05 13:52:03 asau Exp $

DISTNAME=	povray-3.7.0.10
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=POV-Ray/}
GITHUB_PROJECT=	povray
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.povray.org/
COMMENT=	Persistence of Vision Ray Tracer
LICENSE=	gnu-agpl-v3

BUILDLINK_API_DEPENDS.zlib+=	zlib>=1.2.1

AUTOCONF_REQD=		2.59
AUTOMAKE_REQD=		1.9
USE_LANGUAGES=		c c++
GNU_CONFIGURE=		yes
USE_TOOLS=		autoconf automake perl m4 gmake pkg-config
CONFIGURE_ARGS=		--with-boost-thread=boost_thread
CONFIGURE_ARGS+=	--enable-strip
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ENV+=		COMPILED_BY="The NetBSD Packages Collection"

TEST_TARGET=		check

pre-configure:
	set -e; cd ${WRKSRC}/unix && ./prebuild.sh

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH} == x86_64
GCC_REQD+=	3.4
.endif

PKG_SYSCONFSUBDIR=	povray/3.7
EGDIR=			${PREFIX}/share/examples/povray
CONF_FILES=		${EGDIR}/povray.conf ${PKG_SYSCONFDIR}/povray.conf
CONF_FILES+=		${EGDIR}/povray.ini ${PKG_SYSCONFDIR}/povray.ini

INSTALLATION_DIRS=	share/povray-3.7/scripts

.include "../../devel/zlib/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../math/imath/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/openexr/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
