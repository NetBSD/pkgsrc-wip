# $NetBSD: Makefile,v 1.2 2003/05/05 08:24:22 drue Exp $

DISTNAME=		jakarta-log4j-1.2.8
WRKSRC=			${WRKDIR}/${DISTNAME}
CATEGORIES=		devel
MASTER_SITES?=		http://jakarta.apache.org/log4j/

MAINTAINER=		drue@users.sourceforge.net
HOMEPAGE=		http://jakarta.apache.org/log4j/docs/index.html
COMMENT=		Logging facility for Java

USE_BUILDLINK2= yes
USE_JAVA=       run
NO_CONFIGURE=
NO_BUILD=

PLIST_SRC=      ${WRKDIR}/PLIST

DOCDIR=         share/doc/java/jakarta-log4j
EGDIR=          share/examples/java/jakarta-log4j

pre-install:
	@${CP} ${PKGDIR}/PLIST ${PLIST_SRC}
	@(cd ${WRKSRC};                                               \
	${FIND} examples -type f |                                  \
		${SED} -e 's|^examples|${EGDIR}|' | ${SORT} >> ${PLIST_SRC}; \
	${FIND} docs -type f |                                      \
		${SED} -e 's|^docs|${DOCDIR}|' | ${SORT} >> ${PLIST_SRC};    \
	${FIND} examples -type d |                                  \
		${SED} -e 's|^examples|@dirrm ${EGDIR}|' | ${SORT} -r >> ${PLIST_SRC}; \
	${FIND} docs -type d |                                      \
		${SED} -e 's|^docs|@dirrm ${DOCDIR}|' | ${SORT} -r >> ${PLIST_SRC};    \
	${ECHO} '@unexec ${RMDIR} %D/lib/java 2>/dev/null || ${TRUE}' >> ${PLIST_SRC})

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/java
	${INSTALL_DATA} ${WRKSRC}/dist/lib/log4j-1.2.8.jar ${PREFIX}/lib/java
	${INSTALL_DATA_DIR} ${PREFIX}/${DOCDIR}
	${INSTALL_DATA_DIR} ${PREFIX}/${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/LICENSE.txt ${PREFIX}/${DOCDIR}/COPYRIGHT
	${CHMOD} -R ugo-w ${WRKSRC}/examples
	cd ${WRKSRC}/examples && ${PAX} -rw . ${PREFIX}/${EGDIR}
	${CHMOD} -R ugo-w ${WRKSRC}/docs
	cd ${WRKSRC}/docs && ${PAX} -rw . ${PREFIX}/${DOCDIR}

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
