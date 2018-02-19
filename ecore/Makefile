# $NetBSD: Makefile,v 1.39 2013/11/09 14:33:25 roelants Exp $
#

DISTNAME=	ecore-1.7.9
CATEGORIES=	devel
MASTER_SITES=	http://download.enlightenment.org/releases/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	dieter.NetBSD@pandora.be
HOMEPAGE=	http://enlightenment.org/
COMMENT=	Event Abstraction and Modular Convenience Library
LICENSE=	2-clause-bsd

PKGCONFIG_OVERRIDE=	ecore-con.pc.in ecore-evas.pc.in ecore-file.pc.in \
			ecore-imf-evas.pc.in ecore-imf.pc.in \
			ecore-input-evas.pc.in ecore-input.pc.in \
			ecore-ipc.pc.in ecore-x.pc.in ecore.pc.in

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

.if !empty(PKGSRC_RUN_TEST:M[Yy][Ee][Ss])
CONFIGURE_ARGS+=	--enable-tests
# XXX extra entry in PLIST
.endif

TEST_TARGET=		check-local

INSTALLATION_DIRS=	share/doc/ecore

post-install:
	${INSTALL_DATA} ${WRKSRC}/AUTHORS ${WRKSRC}/COPYING \
	    ${DESTDIR}${PREFIX}/share/doc/ecore

.include "../../converters/libiconv/buildlink3.mk"
.if !empty(PKGSRC_RUN_TEST:M[Yy][Ee][Ss])
.include "../../devel/check/buildlink3.mk"
.endif
.include "../../devel/glib2/buildlink3.mk"
.include "../../wip/eet/buildlink3.mk"
.include "../../wip/evas/buildlink3.mk"
#.include "../../wip/evas-gl-x11/buildlink3.mk"
.include "../../wip/evas-software-x11/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../x11/libXScrnSaver/buildlink3.mk"
.include "../../x11/libXcomposite/buildlink3.mk"
.include "../../x11/libXcursor/buildlink3.mk"
.include "../../x11/libXdamage/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXp/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/libXrender/buildlink3.mk"
.include "../../x11/libXtst/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
