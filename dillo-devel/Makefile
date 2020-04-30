# $NetBSD: Makefile,v 1.75 2018/08/22 09:47:24 wiz Exp $

DISTNAME=	dillo-3.0.5
PKGREVISION=	4
CATEGORIES=	www
MASTER_SITES=	https://www.dillo.org/download/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	micha@NetBSD.org
HOMEPAGE=	https://www.dillo.org/
COMMENT=	Very small and fast graphical web-browser
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=		c c++
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFBASEDIR}

REPLACE_PERL+=	dpid/dpidc dillo-install-hyphenation
USE_TOOLS+=	autoconf perl:run wget:run

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
	cd ${WRKSRC} && autoconf

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/*.txt ${DESTDIR}${PREFIX}/share/doc/dillo
	${INSTALL_DATA} ${WRKSRC}/doc/README ${DESTDIR}${PREFIX}/share/doc/dillo

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../wip/fltk14-devel/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
