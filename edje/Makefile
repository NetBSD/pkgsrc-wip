# $NetBSD: Makefile,v 1.35 2012/12/30 19:47:55 roelants Exp $
#

DISTNAME=	edje-1.7.4
CATEGORIES=	graphics
MASTER_SITES=	http://download.enlightenment.org/releases/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	dieter.NetBSD@pandora.be
HOMEPAGE=	http://enlightenment.org/
COMMENT=	Abstract GUI layout and animation object library

# epp binary is GPL
LICENSE=	2-clause-bsd AND gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS=	pkg-config

PKGCONFIG_OVERRIDE=	edje.pc.in

PKG_OPTIONS_VAR=	PKG_OPTIONS.edje
PKG_SUPPORTED_OPTIONS=	python

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	python

.if empty(PKG_OPTIONS:Mpython)
CONFIGURE_ARGS+=	PYTHON=:
.else
PLIST.python=	yes
REPLACE_PYTHON+=	utils/inkscape2edc
.include	"../../lang/python/application.mk"
.endif

INSTALLATION_DIRS+=	share/doc/edje

post-install:
	${INSTALL_DATA} ${WRKSRC}/AUTHORS ${WRKSRC}/COPYING \
	    ${DESTDIR}${PREFIX}/share/doc/edje

.include "../../wip/ecore/buildlink3.mk"
.include "../../wip/eet/buildlink3.mk"
.include "../../wip/eio/buildlink3.mk"
.include "../../wip/evas/buildlink3.mk"
.include "../../wip/embryo/buildlink3.mk"
.include "../../lang/lua/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
