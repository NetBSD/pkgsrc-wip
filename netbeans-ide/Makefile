# $NetBSD: Makefile,v 1.3 2003/05/07 12:34:38 lsed Exp $
#

DISTNAME=	NetBeansIDE-release341
PKGNAME=	netbeans-ide-3.4.1
WRKSRC=		${WRKDIR}/netbeans
CATEGORIES=	editors
MASTER_SITES=	http://www.netbeans.org/download/release341/night/build200301202341/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	drue@users.sourceforge.net
HOMEPAGE=	http://www.netbeans.org/
COMMENT=	NetBeans Java IDE

USE_BUILDLINK2=	yes
USE_X11=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes
USE_JAVA=	run

PLIST_SRC=	${WRKDIR}/PLIST
SHAREDIR=	${PREFIX}/share/${PKGBASE}
DOCDIR=		${PREFIX}/share/doc/html/${PKGBASE}
SHAREDIRS=	beans bin lib modules system tomcat404

pre-install:
	cd ${WRKSRC}/bin && ${RM} -f *.exe *.cmd *.com runide_exe_defaults

do-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	cd ${WRKSRC}/docs && ${PAX} -rw -pm . ${DOCDIR}
	${INSTALL_DATA_DIR} ${SHAREDIR}
	for f in CHANGES.html CREDITS.html README.html README_fr.html README_ru.html netbeans.css; \
	do \
		${INSTALL_DATA} ${WRKSRC}/$${f} ${DOCDIR}; \
	done
	for d in ${SHAREDIRS}; \
	do \
		cd ${WRKSRC} && ${PAX} -rw -pm $${d} ${SHAREDIR}; \
	done
	${INSTALL_DATA} ${WRKSRC}/update_tracking.xml ${SHAREDIR}
	${LN} -sf ${SHAREDIR}/bin/runide.sh  ${PREFIX}/bin/netbeans

post-install:
	${MAKE} print-PLIST > ${PLIST_SRC}

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
