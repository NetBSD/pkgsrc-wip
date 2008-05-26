# $NetBSD: Makefile,v 1.7 2008/05/26 13:59:46 tnn2 Exp $
# $Id: Makefile,v 1.7 2008/05/26 13:59:46 tnn2 Exp $

DISTNAME=	MySQL-python-0.9.2
PKGNAME=	py-mysqldb-docs-0.9.2
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mysql-python/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/mysql-python
COMMENT=	HTML documentation for MySQL interface for Python

NO_BUILD=	yes
NO_CONFIGURE=	# certainly
USE_TOOLS+=	pax

HTMLDIR=	share/doc/${PKGNAME}
DOC_SRCDIR=	${WRKSRC}/doc
PLIST_SRC=	${WRKDIR}/.PLIST_SRC

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/${HTMLDIR}
	${CAT} ${PKGDIR}/PLIST.pre >${PLIST_SRC}
	cd ${DOC_SRCDIR} && pax -rw -pe * ${PREFIX}/${HTMLDIR}
	cd ${PREFIX} && ${FIND} ${HTMLDIR} -type f -print >>${PLIST_SRC}
	cd ${PREFIX} && ${FIND} -d ${HTMLDIR} -type d -print | \
	${SED} -e "s/^/@dirrm /" >>${PLIST_SRC}

.include "../../mk/bsd.pkg.mk"
