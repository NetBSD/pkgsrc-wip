# $NetBSD: Makefile,v 1.15 2012/09/24 18:26:52 asau Exp $

DISTNAME=	castget-2.0.1
CATEGORIES=	audio www
MASTER_SITES=	http://download.savannah.gnu.org/releases/castget/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	netbsd@guigui2.net
HOMEPAGE=	https://castget.johndal.com/
COMMENT=	Command-line RSS enclosures dowloader
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c
USE_TOOLS+=	pkg-config

INSTALLATION_DIRS=	share/examples

post-install:
	${INSTALL_DATA} ${WRKSRC}/castgetrc.example \
		${DESTDIR}${PREFIX}/share/examples/castgetrc.example

PKG_OPTIONS_VAR=	PKG_OPTIONS.castget
PKG_SUPPORTED_OPTIONS=	id3
PKG_SUGGESTED_OPTIONS=	id3

.include "../../mk/bsd.options.mk"
.if !empty(PKG_OPTIONS:Mid3)
.include "../../audio/id3lib/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-id3lib
.endif

.include "../../www/curl/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
