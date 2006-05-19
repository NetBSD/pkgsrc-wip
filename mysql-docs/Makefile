# $NetBSD: Makefile,v 1.5 2006/05/19 16:51:27 ykomatsu Exp $
#

DISTNAME=		manual-split
PKGNAME=		mysql-docs-0
WRKSRC=			${WRKDIR}
CATEGORIES=		misc
MASTER_SITES=		http://mysql.belnet.be/Downloads/Manual/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://mysql.com/
COMMENT=		Latest documentation for MySQL database server

HTMLDIR=	share/doc/${PKGNAME}
PLIST_SRC=	${WRKDIR}/.PLIST_SRC
NO_BUILD=	yes

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/${HTMLDIR}
	${CAT} ${PKGDIR}/PLIST.pre >${PLIST_SRC}
	cd ${WRKSRC} && ${PAX} -rw -pe manual_* ${PREFIX}/${HTMLDIR}
	cd ${PREFIX} && ${FIND} ${HTMLDIR} -type f -print >>${PLIST_SRC}
	cd ${PREFIX} && ${FIND} -d ${HTMLDIR} -type d -print | \
	${SED} -e "s/^/@dirrm /" >>${PLIST_SRC}

.include "../../mk/bsd.pkg.mk"
