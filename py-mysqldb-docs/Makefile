# $NetBSD: Makefile,v 1.9 2012/10/07 12:20:12 asau Exp $
# $Id: Makefile,v 1.9 2012/10/07 12:20:12 asau Exp $

DISTNAME=	MySQL-python-0.9.2
PKGNAME=	py-mysqldb-docs-0.9.2
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mysql-python/}
#LICENSE	GPL or the original license based on Python 1.5.2's license. (at the time python's license is CNRI)

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://sourceforge.net/projects/mysql-python
COMMENT=	HTML documentation for MySQL interface for Python

NO_BUILD=	yes
NO_CONFIGURE=	# certainly
USE_TOOLS+=	pax

HTMLDIR=	share/doc/${PKGNAME}
DOC_SRCDIR=	${WRKSRC}/doc
PLIST_SRC=	${WRKDIR}/.PLIST_SRC

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/${HTMLDIR}
	${CAT} ${PKGDIR}/PLIST.pre >${PLIST_SRC}
	cd ${DOC_SRCDIR} && pax -rw -pe * ${DESTDIR}${PREFIX}/${HTMLDIR}
	cd ${DESTDIR}${PREFIX} && ${FIND} ${HTMLDIR} -type f -print >>${PLIST_SRC}

.include "../../mk/bsd.pkg.mk"
