# $NetBSD: Makefile,v 1.2 2004/09/13 21:10:33 shattered Exp $
#

DISTNAME=		rel-bacula-doc
PKGNAME=		bacula-docs-1.34.5
WRKSRC=			${WRKDIR}/html-manual
CATEGORIES=		sysutils
MASTER_SITES=		http://www.bacula.org/
DIST_SUBDIR=		${PKGNAME}

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://www.bacula.org/
COMMENT=		Documentation for Bacula - The Network Backup Solution

NO_CONFIGURE=	yes
NO_BUILD=	yes

HTMLDIR=	share/doc/bacula
PLIST_SRC=	${WRKDIR}/.PLIST_SRC

post-extract:
	${RM} -rf ${WRKSRC}/CVS ${WRKSRC}/publishdoc ${WRKSRC}/*.bak

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/${HTMLDIR}
	${CAT} ${PKGDIR}/PLIST.pre >${PLIST_SRC}
	cd ${WRKSRC} && ${PAX} -rw -pe [A-Za-z]* ${PREFIX}/${HTMLDIR}
	cd ${PREFIX} && ${FIND} ${HTMLDIR} -type f -print >>${PLIST_SRC}
	cd ${PREFIX} && ${FIND} -d ${HTMLDIR} -type d -print | \
	${SED} -e "s/^/@dirrm /" >>${PLIST_SRC}

.include "../../mk/bsd.pkg.mk"
