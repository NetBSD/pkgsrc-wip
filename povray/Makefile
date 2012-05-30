# $NetBSD: Makefile,v 1.1.1.1 2012/05/30 11:42:50 thomasklausner Exp $

DISTNAME=	povray-3.7.0.RC3
PKGNAME=	${DISTNAME:S/.RC/rc/}
CATEGORIES=	graphics
MASTER_SITES=	http://povray.org/redirect/www.povray.org/beta/source/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.povray.org/
COMMENT=	Persistence of Vision Ray Tracer
LICENSE=	povray-license

PKG_DESTDIR_SUPPORT=	user-destdir

BUILDLINK_API_DEPENDS.zlib+=	zlib>=1.2.1

USE_LANGUAGES=		c c++
GNU_CONFIGURE=		yes
USE_TOOLS=		gmake pkg-config
CONFIGURE_ARGS+=	--disable-optimiz
CONFIGURE_ARGS+=	--enable-strip
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ENV+=		COMPILED_BY="The NetBSD Packages Collection"

TEST_TARGET=		check

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH} == x86_64
GCC_REQD+=	3.4
.endif

PLIST_SUBST+=	POVRAY=povray-3.7

EGDIR=		${PREFIX}/share/examples/povray
CONF_FILES=	${EGDIR}/povray.conf ${PKG_SYSCONFDIR}/povray.conf
CONF_FILES+=	${EGDIR}/povray.ini ${PKG_SYSCONFDIR}/povray.ini

INSTALLATION_DIRS=	share/povray-3.7/scripts

.include "../../devel/zlib/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/openexr/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
