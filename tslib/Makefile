# $NetBSD$

DISTNAME=	tslib-1.16
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=kergoth/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tslib.org/
COMMENT=	Touchscreen access library
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=		yes
USE_TOOLS+=		autoconf automake
USE_LIBTOOL=		yes

EGDIR=			${PREFIX}/share/examples/tslib
CONFIGURE_ARGS+=	--sysconfdir=${EGDIR}
CONF_FILES+=		${EGDIR}/ts.conf ${PKG_SYSCONFDIR}/ts.conf

pre-configure:
	(cd ${WRKSRC}; ./autogen.sh)

.include "../../mk/bsd.prefs.mk"

PLIST_VARS+=		input waveshare

.if ${OPSYS} != "Linux" && ${OPSYS} != "FreeBSD"
# Disable /dev/input/eventN support
CONFIGURE_ARGS+=	--disable-input
.else
PLIST.input=		yes
.endif

.if ${OPSYS} != "Linux"
CONFIGURE_ARGS+=	--disable-waveshare
.else
PLIST.waveshare=	yes
.endif

.include "../../mk/bsd.pkg.mk"
