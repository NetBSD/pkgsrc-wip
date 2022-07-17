# $NetBSD$

DISTNAME=	libnfc-1.8.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=nfc-tools/libnfc/releases/download/libnfc-1.8.0/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	lefinnois@lefinnois.net
HOMEPAGE=	http://nfc-tools.org/index.php?title=Libnfc
COMMENT=	Low level NFC SDK and Programmers API
LICENSE=	gnu-lgpl-v3

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES+=	c c++

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

EGDIR=			${PREFIX}/share/examples/libnfc
CONF_FILES+=		${EGDIR}/libnfc.conf ${PKG_SYSCONFDIR}/nfc/libnfc.conf
OWN_DIRS+=		${PKG_SYSCONFDIR}/nfc

.include "options.mk"

PKGCONFIG_OVERRIDE+=	libnfc.pc.in

SUBST_CLASSES+=		adjust
SUBST_STAGE.adjust=	pre-configure
SUBST_FILES.adjust=	libnfc.conf.sample
SUBST_SED.adjust+=	-e 's,ttyUSB0,ttyU0,'

INSTALLATION_DIRS=	${EGDIR}

post-install:
	${INSTALL_DATA} ${WRKSRC}/libnfc.conf.sample ${DESTDIR}${EGDIR}/libnfc.conf

.include "../../devel/readline/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
