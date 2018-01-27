# $NetBSD: Makefile,v 1.8 2014/05/09 07:38:42 thomasklausner Exp $

DISTNAME=	cycle-0.3.1
PKGREVISION=	3
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=cycle/}
EXTRACT_SUFX=	.tar.bz2
NO_BUILD=	yes

MAINTAINER=	ckoeni@gmail.com
HOMEPAGE=	http://cycle.sourceforge.net/
COMMENT=	Cycle is a fertility calendar program for women

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 # py-wxWidgets
REPLACE_PYTHON=	cycle.py

INSTALLATION_DIRS=	lib/cycle lib/cycle/bitmaps \
	lib/cycle/icons lib/cycle/icons/large lib/cycle/icons/mini \
	lib/cycle/msg lib/cycle/msg/ca/LC_MESSAGES \
	lib/cycle/msg/cs/LC_MESSAGES lib/cycle/msg/de/LC_MESSAGES \
	lib/cycle/msg/es/LC_MESSAGES lib/cycle/msg/gl/LC_MESSAGES \
	lib/cycle/msg/ru/LC_MESSAGES lib/cycle/msg/sk/LC_MESSAGES \
	bin ${PKGMANDIR}/man1	# XXX man quick fix

do-install:
	${INSTALL_DATA} ${WRKSRC}/cycle.1  ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/
	${INSTALL_DATA} ${WRKSRC}/*.py ${DESTDIR}${PREFIX}/lib/cycle/
	${INSTALL_DATA} ${WRKSRC}/README* ${DESTDIR}${PREFIX}/lib/cycle/
	${INSTALL_DATA} ${WRKSRC}/bitmaps/* ${DESTDIR}${PREFIX}/lib/cycle/bitmaps
	${INSTALL_DATA} ${WRKSRC}/icons/cycle* ${DESTDIR}${PREFIX}/lib/cycle/icons
	${INSTALL_DATA} ${WRKSRC}/icons/large/cycle* ${DESTDIR}${PREFIX}/lib/cycle/icons/large
	${INSTALL_DATA} ${WRKSRC}/icons/mini/cycle* ${DESTDIR}${PREFIX}/lib/cycle/icons/mini
	${INSTALL_DATA} ${WRKSRC}/msg/*po ${DESTDIR}${PREFIX}/lib/cycle/msg
	${INSTALL_DATA} ${WRKSRC}/msg/*py ${DESTDIR}${PREFIX}/lib/cycle/msg
	${INSTALL_DATA} ${WRKSRC}/msg/*pot ${DESTDIR}${PREFIX}/lib/cycle/msg
	${INSTALL_DATA} ${WRKSRC}/msg/ca/LC_MESSAGES/* ${DESTDIR}${PREFIX}/lib/cycle/msg/ca/LC_MESSAGES
	${INSTALL_DATA} ${WRKSRC}/msg/cs/LC_MESSAGES/* ${DESTDIR}${PREFIX}/lib/cycle/msg/cs/LC_MESSAGES
	${INSTALL_DATA} ${WRKSRC}/msg/de/LC_MESSAGES/* ${DESTDIR}${PREFIX}/lib/cycle/msg/de/LC_MESSAGES
	${INSTALL_DATA} ${WRKSRC}/msg/es/LC_MESSAGES/* ${DESTDIR}${PREFIX}/lib/cycle/msg/es/LC_MESSAGES
	${INSTALL_DATA} ${WRKSRC}/msg/gl/LC_MESSAGES/* ${DESTDIR}${PREFIX}/lib/cycle/msg/gl/LC_MESSAGES
	${INSTALL_DATA} ${WRKSRC}/msg/ru/LC_MESSAGES/* ${DESTDIR}${PREFIX}/lib/cycle/msg/ru/LC_MESSAGES
	${INSTALL_DATA} ${WRKSRC}/msg/sk/LC_MESSAGES/* ${DESTDIR}${PREFIX}/lib/cycle/msg/sk/LC_MESSAGES

	cd ${DESTDIR}${PREFIX}/lib/cycle/ && chmod -R 0755 *
	chmod -R 0755 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/cycle.1
	${ECHO} 'cd /usr/pkg/lib/cycle/ && exec ./cycle.py' > ${DESTDIR}${PREFIX}/bin/cycle
	chmod -R 0755 ${DESTDIR}${PREFIX}/bin/cycle

.include "../../lang/python/application.mk"
.include "../../x11/py-wxWidgets/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
