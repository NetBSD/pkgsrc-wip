# $NetBSD: Makefile,v 1.5 2011/11/21 19:08:57 absd Exp $
#

DISTNAME=		Fnorb-Guide.html
PKGNAME=		py-Fnorb-docs-0
WRKSRC=			${WRKDIR}/Fnorb-Guide
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=fnorb/}
EXTRACT_SUFX=		.tgz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://fnorb.sourceforge.net/
COMMENT=		Documentation for py-Fnorb in HTML format

NO_CONFIGURE=	yes
NO_BUILD=	yes
USE_TOOLS+=	pax

HTMLDIR=	share/doc/${PKGNAME}
PLIST_SRC=	${WRKDIR}/.PLIST_SRC

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/${HTMLDIR}
	${CAT} ${PKGDIR}/PLIST.pre >${PLIST_SRC}
	cd ${WRKSRC} && pax -rw -pe * ${PREFIX}/${HTMLDIR}
	cd ${PREFIX} && ${FIND} ${HTMLDIR} -type f -print >>${PLIST_SRC}

.include "../../mk/bsd.pkg.mk"
