# $NetBSD: Makefile,v 1.1.1.1 2003/07/22 12:21:10 marc Exp $

DISTNAME=	j2sdk-1_4_2-linux-i586
PKGNAME=	sun-jdk142-0.0
WRKSRC=		${WRKDIR}/j2sdk1.4.2
MASTER_SITES=	# empty

COMMENT=	Sun's Java(tm) 2 SDK, Standard Edition 1.4.2

DEPENDS=	sun-jre142>=0.0:../../wip/sun-jre142

# Remove parts that are in common with the JRE
#
post-extract:
	common=`${AWK} '/^#.*/ { next } /^$$/ { next } { print }' ${FILESDIR}/common`; \
	cd ${WRKSRC}; for i in $$common; do				\
		if [ -d $$i ]; then					\
			${RM} -rf $$i;					\
		else							\
			${RM} -f $$i;					\
		fi;							\
	done
	${LN} -sf . ${WRKSRC}/jre

_FETCH_MESSAGE= \
	${ECHO} "======================================================================"; \
	${ECHO} ; \
	${ECHO} " The file ${DISTNAME}${EXTRACT_SUFX} containing the"; \
	${ECHO} " Java(tm) 2 SDK, Standard Edition must be fetched"; \
	${ECHO} " into:"; \
	${ECHO} "	${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}"; \
	${ECHO} " from:"; \
	${ECHO} "	${DOWNLOAD}"; \
	${ECHO} ; \
	${ECHO} " Choose 'Linux self-extracting file' from the 'SDK' column."; \
	${ECHO} ; \
	${ECHO} "======================================================================"

.include "../../wip/sun-jre142/Makefile.common"

PREFIX=		${JVM_HOME}
