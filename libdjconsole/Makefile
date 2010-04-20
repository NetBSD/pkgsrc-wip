# $NetBSD: Makefile,v 1.2 2010/04/20 03:36:49 othyro Exp $
#

DISTNAME=	libdjconsole-0.1.3
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=djplay/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://djplay.sourceforge.net/
COMMENT=	DJ Console access library

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

PKG_DESTDIR_SUPPORT=	user-destdir

PKGCONFIG_OVERRIDE+=	libdjconsole.pc.in

EGDIR=			${PREFIX}/share/examples/udev/rules.d
INSTALLATION_DIRS+=	include/libdjconsole lib/pkgconfig share/libdjconsole

DATA_FILES=		bitfield.h delta.h djconsole.h

do-install:
	for a in ${DATA_FILES}; do \
		${INSTALL_DATA} ${WRKSRC}/$$a ${DESTDIR}${PREFIX}/include/libdjconsole/$$a; \
	done
	${INSTALL_LIB} ${WRKSRC}/libdjconsole.la ${DESTDIR}${PREFIX}/lib/libdjconsole.la
	${INSTALL_DATA} ${WRKSRC}/libdjconsole.pc ${DESTDIR}${PREFIX}/lib/pkgconfig/libdjconsole.pc
	${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/45-hpdjconsole.rules ${DESTDIR}${EGDIR}/45-hpdjconsole.rules
	cd ${WRKSRC} && for b in 06f8-*; do \
		${INSTALL_DATA} $$b ${DESTDIR}${PREFIX}/share/libdjconsole/$$b; \
	done

.include "../../devel/libusb/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
