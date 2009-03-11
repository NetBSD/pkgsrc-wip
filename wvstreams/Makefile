# $NetBSD: Makefile,v 1.1.1.1 2009/03/11 14:14:51 udontknow Exp $
#

DISTNAME=	wvstreams-4.5.1
CATEGORIES=	net
MASTER_SITES=	http://wvstreams.googlecode.com/files/

MAINTAINER=	evaldo@gardenali.biz
HOMEPAGE=	http://wvstreams.googlecode.com/files/
COMMENT=	WvStreams is a network programming library in C++

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake pkg-config
USE_LANGUAGES=	c c++
PKG_DESTDIR_SUPPORT=    user-destdir

EGDIR=                  ${PREFIX}/share/examples/wvstreams
CONF_FILES=             ${EGDIR}/uniconf.conf ${PKG_SYSCONFDIR}/uniconf.conf

SUBST_CLASSES+=         etc
SUBST_STAGE.etc=        pre-install
SUBST_FILES.etc=       	install.mk
SUBST_SED.etc=          -e 's:$$(sysconfdir):${EGDIR}:g'
SUBST_MESSAGE.etc=      Fixing examples directory

PKGCONFIG_OVERRIDE+=	pkgconfig/libwvtest.pc.in
PKGCONFIG_OVERRIDE+=	pkgconfig/libwvstreams.pc.in
PKGCONFIG_OVERRIDE+=	pkgconfig/libwvbase.pc.in
PKGCONFIG_OVERRIDE+=	pkgconfig/libwvdbus.pc.in
PKGCONFIG_OVERRIDE+=	pkgconfig/libwvutils.pc.in
PKGCONFIG_OVERRIDE+=	pkgconfig/libuniconf.pc.in
PKGCONFIG_OVERRIDE+=	pkgconfig/libwvqt.pc.in

.include "../../mk/bsd.pkg.mk"
