# $NetBSD: Makefile,v 1.7 2005/07/27 16:25:57 thomasklausner Exp $
#

DISTNAME=		# defined
PKGNAME=		kylix-openedition-3.0
CATEGORIES=		devel
MASTER_SITES=		http://altd.borland.com/download/kylix/k3/ \
			ftp://ftpd.borland.com/download/kylix/k3/
DISTFILES=		k3_open_update_2.tar.gz kylix3_open.tar.gz

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.borland.com/kylix/open/
COMMENT=		ANSI/ISO C++, Delphi and IDE in one

DEPENDS+=		${LINUX_BASE_PREFIX}_gtk-[0-9]*:../../emulators/${LINUX_BASE_PREFIX}_gtk

LINUX_BINPKG_FMT=	plain
LINUX_USE_X11=		yes

NO_SRC_ON_CDROM=	"I'm not sure if we can redistribute it"
NO_BIN_ON_CDROM=	${NO_SRC_ON_CDROM}

post-extract:
	cd ${WRKDIR}/kylix3_open && ${TAR} -xzvf runimage.tar.gz

post-patch:
	cd ${WRKDIR}/k3_open_update_2 && ./install.sh ${WRKDIR}/kylix3_open/runimage/kylix

TARGET_DIR=	${EMULOPTDIR}/kylix

do-install:
	${INSTALL_DATA_DIR} ${TARGET_DIR}
	cd ${WRKDIR}/kylix3_open/runimage/kylix && ${PAX} -rw -pe * ${TARGET_DIR}
	${LN} -s ${EMULOPTDIR}/bin/libwine.borland.so.1.0 ${EMULDIR}/usr/lib/libwine.borland.so
	${LN} -s ${EMULOPTDIR}/bin/libwine_unicode.borland.so.1.0 ${EMULDIR}/usr/lib/libwine_unicode.borland.so
	${CAT} ${PKGDIR}/PLIST.pre >${PLIST_SRC}
	cd ${EMULOPTDIR} && ${FIND} kylix -type f | \
		${SED} -e "s|^|\$${EMULOPTSUBDIR}/|" >> ${PLIST_SRC}
	cd ${EMULOPTDIR} && ${FIND} kylix -type l | \
		${SED} -e "s|^|\$${EMULOPTSUBDIR}/|" >> ${PLIST_SRC}
	cd ${EMULOPTDIR} && ${FIND} -d kylix  -type d  | \
	${SED} -e "s/^/@dirrm \$${EMULOPTSUBDIR}\//" >>${PLIST_SRC}
	${CAT} ${PKGDIR}/PLIST.post >> ${PLIST_SRC}

.include "../../wip/mk/linuxbin.pkg.mk"
.include "../../mk/bsd.pkg.mk"
