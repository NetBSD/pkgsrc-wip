# $NetBSD: Makefile,v 1.1.1.1 2004/01/06 02:31:34 mpasternak Exp $
# $Id: Makefile,v 1.1.1.1 2004/01/06 02:31:34 mpasternak Exp $

DISTNAME=       MySQL-python-0.9.2
PKGNAME=        py-mysqldb-docs-0.9.2
CATEGORIES=     databases                                
MASTER_SITES=   ${MASTER_SITE_SOURCEFORGE:=mysql-python/}          

MAINTAINER=     dotz@irc.pl                                
HOMEPAGE=       http://sourceforge.net/projects/mysql-python             
COMMENT=        HTML documentation for MySQL interface for Python                                
                                                                  
NO_BUILD=	# defined
NO_CONFIGURE=	# certainly

HTMLDIR=	share/doc/${PKGNAME}
DOC_SRCDIR=	${WRKSRC}/doc
PLIST_SRC=	${WRKDIR}/.PLIST_SRC

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/${HTMLDIR}
	${CAT} ${PKGDIR}/PLIST.pre >${PLIST_SRC}
	cd ${DOC_SRCDIR} && ${PAX} -rw -pe * ${PREFIX}/${HTMLDIR}
	cd ${PREFIX} && ${FIND} ${HTMLDIR} -type f -print >>${PLIST_SRC}
	cd ${PREFIX} && ${FIND} -d ${HTMLDIR} -type d -print | \
	${SED} -e "s/^/@dirrm /" >>${PLIST_SRC}

.include "../../mk/bsd.pkg.mk"
