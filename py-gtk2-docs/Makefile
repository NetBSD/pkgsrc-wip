# $NetBSD: Makefile,v 1.6 2011/11/21 19:08:57 absd Exp $
#

DISTNAME=		py-gtk2-docs
PKGNAME=		py-gtk2-docs-1
WRKSRC=			${WRKDIR}
CATEGORIES=		devel
MASTER_SITES=		http://www.moeraki.com/pygtktutorial/ \
			http://www.moeraki.com/pygtkreference/
DISTFILES=		pygtk2tutorial.tgz pygtk2reference.tgz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.moeraki.com/
COMMENT=		Tutorial and reference manual for PyGTK 2.0

NO_BUILD=	# yes, certainly
NO_CONFIGURE=	# heck, why not!
USE_TOOLS+=	pax

HTMLDIR=	share/doc/${DISTNAME}
DOC_SRCDIR=	${WRKSRC}
PLIST_SRC=	${WRKDIR}/.PLIST_SRC

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/${HTMLDIR}
	${CAT} ${PKGDIR}/PLIST.pre >${PLIST_SRC}
	cd ${DOC_SRCDIR} && pax -rw -pe pygtk* ${PREFIX}/${HTMLDIR}
	cd ${PREFIX} && ${FIND} ${HTMLDIR} -type f -print >>${PLIST_SRC}

.include "../../mk/bsd.pkg.mk"
