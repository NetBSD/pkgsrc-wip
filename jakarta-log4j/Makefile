# $NetBSD: Makefile,v 1.1.1.1 2003/05/02 11:10:25 drue Exp $

DISTNAME=		jakarta-log4j-1.2.8
WRKSRC=			${WRKDIR}/${DISTNAME}
CATEGORIES=		devel
MASTER_SITES?=		http://jakarta.apache.org/log4j/

MAINTAINER=		drue@users.sourceforge.net
HOMEPAGE=		http://jakarta.apache.org/log4j/docs/index.html
COMMENT=		Logging facility for Java

USE_JAVA=       run
NO_CONFIGURE=
NO_BUILD=

PLIST_SRC=      ${WRKDIR}/PLIST

EXAMPLEDIR=		share/examples/java/jakarta-log4j
DOCDIR=			share/doc/java/jakarta-log4j

#EDIRS!=         cd ${WRKSRC}/examples && ${FIND} . -type d
#EFILES!=        cd ${WRKSRC}/examples &&  ${FIND} . -type f
#DDIRS!=         cd ${WRKSRC}/docs && ${FIND} . -type d
#DFILES!=        cd ${WRKSRC}/docs && ${FIND} . -type f

pre-install:
	@${CP} ${PKGDIR}/PLIST ${PLIST_SRC}
#	@(cd ${WRKSRC};                                               \
#	  ${FIND} examples -type f |                                  \
#		${SED} -e 's|^examples|${EXAMPLEDIR}|' | sort >> ${PLIST_SRC}; \
#	  ${FIND} docs -type f |                                      \
#		${SED} -e 's|^docs|${DOCDIR}|' | sort >> ${PLIST_SRC};    \
#	  ${FIND} examples -type d |                                  \
#		${SED} -e 's|^examples|@dirrm ${EXAMPLEDIR}|' | sort -r >> ${PLIST_SRC}; \
#	  ${FIND} docs -type d |                                      \
#		${SED} -e 's|^docs|@dirrm ${DOCDIR}|' | sort -r >> ${PLIST_SRC};    \
#	  ${ECHO} '@unexec ${RMDIR} %D/lib/java 2>/dev/null || ${TRUE}' >> ${PLIST_SRC})

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/java
	${INSTALL_DATA} ${WRKSRC}/dist/lib/log4j-1.2.8.jar ${PREFIX}/lib/java
	${INSTALL_DATA_DIR} ${PREFIX}/${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/LICENSE.txt ${PREFIX}/${DOCDIR}/COPYRIGHT
#.for i in ${DDIRS}
#	${INSTALL_DATA_DIR} ${PREFIX}/${DOCDIR}/$i
#.endfor
#.for i in ${DFILES}
#	${INSTALL_DATA} ${PREFIX}/${DOCDIR}/$i
#.endfor
#	${INSTALL_DATA_DIR} ${PREFIX}/${EXAMPLEDIR}
#.for i in ${EDIRS}
#	${INSTALL_DATA_DIR} ${PREFIX}/${EXAMPLEDIR}/$i
#.endfor
#.for i in ${EFILES}
#	${INSTALL_DATA} ${PREFIX}/${EXAMPLEDIR}/$i
#.endfor

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
