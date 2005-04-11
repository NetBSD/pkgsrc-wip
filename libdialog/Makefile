# $NetBSD: Makefile,v 1.4 2005/04/11 21:13:46 tvierling Exp $

DISTNAME=		libdialog-0.4
CATEGORIES=		devel
MASTER_SITES=		http://energyhq.homeip.net/files/

MAINTAINER=		flynn@energyhq.homeip.net
COMMENT=		Port of FreeBSD's console menu system

USE_NCURSES=		YES

do-install:
	for i in libdialog.so libdialog.so.0 libdialog.so.0.4; \
	do \
		${INSTALL_PROGRAM} ${WRKSRC}/$${i} ${PREFIX}/lib; \
	done
	for i in colors.h rc.h dialog.h dir.h ui_objects.h; \
	do \
		${INSTALL_DATA} ${WRKSRC}/$${i} ${PREFIX}/include; \
	done
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/libdialog
	for i in ${WRKSRC}/TESTS/*; \
	do \
		${INSTALL_DATA} $${i} ${PREFIX}/share/examples/libdialog; \
	done

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
