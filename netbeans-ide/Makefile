# $NetBSD: Makefile,v 1.1.1.1 2003/05/05 12:53:36 drue Exp $

DISTNAME=		NetBeansIDE-release341
PKGNAME=		netbeans-3.4.1
WRKSRC=			${WRKDIR}/netbeans
CATEGORIES=		editors
MASTER_SITES=		http://www.netbeans.org/download/release341/night/build200301202341/
EXTRACT_SUFX= 		.tar.bz2

MAINTAINER=		drue@users.sourceforge.net
HOMEPAGE=		http://www.netbeans.org/
COMMENT=		NetBeans Java IDE

USE_BUILDLINK2= yes
USE_JAVA=       run
USE_X11=	yes
NO_CONFIGURE=
NO_BUILD=

PLIST_SRC=      ${WRKDIR}/PLIST

SHAREDIR=       share/netbeans-ide
DOCDIR=         share/doc/netbeans-ide
SHAREDIRS=	beans bin lib modules system tomcat404
#WASTEBIN=   runide.exe runideopenvms.com rmid_wrapper.exe runideos2.cmd macosx_launcher.dmg runide_exe_defaults   runidew.exe

pre-install:
	@${CP} ${PKGDIR}/PLIST ${PLIST_SRC}
	@(cd ${WRKSRC};                                                   \
	${FIND} ${SHAREDIRS} -type f |          \
		${SED} -e 's|^|${SHAREDIR}/|' | ${SORT} >> ${PLIST_SRC}; \
	${FIND} docs -type f |				              		   \
		${SED} -e 's|^|${DOCDIR}/|' | ${SORT} >> ${PLIST_SRC}; 	   \
	${FIND} ${SHAREDIRS} -type d |  		                           \
		${SED} -e 's|^|@dirrm ${SHAREDIR}/|' | ${SORT} -r >> ${PLIST_SRC}; \
	${FIND} docs -type d |			                       		   \
		${SED} -e 's|^|@dirrm ${DOCDIR}/|' | ${SORT} -r >> ${PLIST_SRC};)

do-install:
	${CHMOD} -R ugo-w ${WRKSRC}
	${INSTALL_DATA_DIR} ${PREFIX}/${DOCDIR}
	for f in CHANGES.html CREDITS.html README.html README_fr.html README_ru.html netbeans.css; \
	do \
		${INSTALL_DATA} ${WRKSRC}/$${f} ${PREFIX}/${DOCDIR}; \
	done
	@( cd ${WRKSRC} && ${PAX} -rw docs ${PREFIX}/${DOCDIR} )
	${INSTALL_DATA_DIR} ${PREFIX}/${SHAREDIR}
	for f in ${SHAREDIRS}; \
	do \
		(cd ${WRKSRC} && ${PAX} -rw $${f} ${PREFIX}/${SHAREDIR} ) \
	done
	${INSTALL_DATA} ${WRKSRC}/update_tracking.xml ${PREFIX}/${SHAREDIR}
	${LN} -sf ${PREFIX}/${SHAREDIR}/bin/runide.sh  ${PREFIX}/bin/netbeans

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
