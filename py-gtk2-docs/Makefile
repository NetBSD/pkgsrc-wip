# $NetBSD: Makefile,v 1.8 2014/01/25 10:38:19 thomasklausner Exp $

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

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/${HTMLDIR}
	cd ${DOC_SRCDIR} && pax -rw -pe pygtk* ${DESTDIR}${PREFIX}/${HTMLDIR}

.include "../../mk/bsd.pkg.mk"
