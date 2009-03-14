# $NetBSD: Makefile,v 1.1.1.1 2009/03/14 05:38:53 othyro Exp $
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

DATA_FILES=		bitfield.h delta.h djconsole.h

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}/${PREFIX}/include/libdjconsole
	for a in ${DATA_FILES}; do \
		${INSTALL_DATA} ${WRKSRC}/$$a ${DESTDIR}/${PREFIX}/include/libdjconsole/$$a; \
	done
	${INSTALL_LIB_DIR} ${DESTDIR}/${PREFIX}/lib
	${INSTALL_LIB} ${WRKSRC}/libdjconsole.la ${DESTDIR}/${PREFIX}/lib/libdjconsole.la
	${INSTALL_DATA_DIR} ${DESTDIR}/${PREFIX}/lib/pkgconfig
	${INSTALL_DATA} ${WRKSRC}/libdjconsole.pc ${DESTDIR}/${PREFIX}/lib/pkgconfig/libdjconsole.pc
	${INSTALL_DATA_DIR} ${DESTDIR}/${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/45-hpdjconsole.rules ${DESTDIR}/${EGDIR}/45-hpdjconsole.rules
	${INSTALL_DATA_DIR} ${DESTDIR}/${PREFIX}/share/libdjconsole
	cd ${WRKSRC} && for b in 06f8-*; do \
		${INSTALL_DATA} $$b ${DESTDIR}/${PREFIX}/share/libdjconsole/$$b; \
	done

.include "../../devel/libusb/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
