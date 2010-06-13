# $NetBSD: Makefile,v 1.4 2010/06/13 22:46:58 thomasklausner Exp $
#

DISTNAME=	cycle-0.3.1
PKGREVISION=	2
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=cycle/}
EXTRACT_SUFX=	.tar.bz2
NO_BUILD=	yes
PYTHON_PATCH_SCRIPTS=	cycle.py

MAINTAINER=	ckoeni@gmail.com
HOMEPAGE=	http://cycle.sourceforge.net/
COMMENT=	Cycle is a fertility calendar program for women

INSTALLATION_DIRS= lib/cycle lib/cycle/bitmaps \
	lib/cycle/icons lib/cycle/icons/large lib/cycle/icons/mini \
	lib/cycle/msg lib/cycle/msg/ca/LC_MESSAGES \
	lib/cycle/msg/cs/LC_MESSAGES lib/cycle/msg/de/LC_MESSAGES \
	lib/cycle/msg/es/LC_MESSAGES lib/cycle/msg/gl/LC_MESSAGES \
	lib/cycle/msg/ru/LC_MESSAGES lib/cycle/msg/sk/LC_MESSAGES

do-install:
	${INSTALL_DATA} ${WRKSRC}/cycle.1  ${PREFIX}/${PKGMANDIR}/man1/
	${INSTALL_DATA} ${WRKSRC}/*.py ${PREFIX}/lib/cycle/
	${INSTALL_DATA} ${WRKSRC}/README* ${PREFIX}/lib/cycle/
	${INSTALL_DATA} ${WRKSRC}/bitmaps/* ${PREFIX}/lib/cycle/bitmaps
	${INSTALL_DATA} ${WRKSRC}/icons/cycle* ${PREFIX}/lib/cycle/icons
	${INSTALL_DATA} ${WRKSRC}/icons/large/cycle* ${PREFIX}/lib/cycle/icons/large
	${INSTALL_DATA} ${WRKSRC}/icons/mini/cycle* ${PREFIX}/lib/cycle/icons/mini
	${INSTALL_DATA} ${WRKSRC}/msg/*po ${PREFIX}/lib/cycle/msg
	${INSTALL_DATA} ${WRKSRC}/msg/*py ${PREFIX}/lib/cycle/msg
	${INSTALL_DATA} ${WRKSRC}/msg/*pot ${PREFIX}/lib/cycle/msg
	${INSTALL_DATA} ${WRKSRC}/msg/ca/LC_MESSAGES/* ${PREFIX}/lib/cycle/msg/ca/LC_MESSAGES
	${INSTALL_DATA} ${WRKSRC}/msg/cs/LC_MESSAGES/* ${PREFIX}/lib/cycle/msg/cs/LC_MESSAGES
	${INSTALL_DATA} ${WRKSRC}/msg/de/LC_MESSAGES/* ${PREFIX}/lib/cycle/msg/de/LC_MESSAGES
	${INSTALL_DATA} ${WRKSRC}/msg/es/LC_MESSAGES/* ${PREFIX}/lib/cycle/msg/es/LC_MESSAGES
	${INSTALL_DATA} ${WRKSRC}/msg/gl/LC_MESSAGES/* ${PREFIX}/lib/cycle/msg/gl/LC_MESSAGES
	${INSTALL_DATA} ${WRKSRC}/msg/ru/LC_MESSAGES/* ${PREFIX}/lib/cycle/msg/ru/LC_MESSAGES
	${INSTALL_DATA} ${WRKSRC}/msg/sk/LC_MESSAGES/* ${PREFIX}/lib/cycle/msg/sk/LC_MESSAGES

	cd ${PREFIX}/lib/cycle/ && chmod -R 0755 *
	chmod -R 0755 ${PREFIX}/${PKGMANDIR}/man1/cycle.1
	${ECHO} 'cd /usr/pkg/lib/cycle/ && exec ./cycle.py' > ${PREFIX}/bin/cycle
	chmod -R 0755 ${PREFIX}//bin/cycle

.include "../../lang/python/application.mk"
.include "../../x11/py-wxWidgets/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
