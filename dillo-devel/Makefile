# $NetBSD$

DISTNAME=	dillo-3.2.0
CATEGORIES=	www

MASTER_SITES=	${MASTER_SITE_GITHUB:=dillo-browser/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	micha@NetBSD.org
HOMEPAGE=	https://dillo-browser.github.io/
COMMENT=	Very small and fast graphical web-browser
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	c c++

USE_TOOLS+=	autoconf automake autoreconf perl:run
USE_FEATURES+=	snprintf vsnprintf

DEPENDS+=	wget-[0-9]*:../../net/wget

REPLACE_PERL+=	dillo-install-hyphenation

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFBASEDIR}
CONFIGURE_ARGS+=	--disable-xembed
CONFIGURE_ARGS+=	--enable-cookies

PKG_SYSCONFSUBDIR=	dillo
EGDIR=			${PREFIX}/share/examples/dillo
CONF_FILES=		${EGDIR}/dillorc ${PKG_SYSCONFDIR}/dillorc
CONF_FILES+=		${EGDIR}/dpidrc ${PKG_SYSCONFDIR}/dpidrc
CONF_FILES+=		${EGDIR}/keysrc ${PKG_SYSCONFDIR}/keysrc
CONF_FILES+=		${EGDIR}/domainrc ${PKG_SYSCONFDIR}/domainrc

INSTALLATION_DIRS=	share/doc/dillo ${EGDIR}

INSTALL_MAKE_FLAGS+=	sysconfdir=${EGDIR}

LIBS.SunOS+=	-liconv

.include "options.mk"

pre-configure:
	cd ${WRKSRC} && autoreconf -fiv

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../x11/fltk/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
