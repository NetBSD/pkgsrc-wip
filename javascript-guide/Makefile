# $NetBSD: Makefile,v 1.9 2011/11/21 19:08:56 absd Exp $
#

DISTNAME=		CoreGuideJS15
PKGNAME=		javascript-guide-1.5
CATEGORIES=		misc
MASTER_SITES=		http://devedge-temp.mozilla.org/library/manuals/2000/javascript/1.5/guide/
EXTRACT_SUFX=		.zip

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://devedge-temp.mozilla.org/
COMMENT=		JavaScript Guide from Netscape Devedge

HTMLDIR=		share/doc/${PKGNAME}
RESTRICTED=		I am not sure if we can redistribute it
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BUILD=		yes
USE_TOOLS+=		pax

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/${HTMLDIR}
	cat ${PKGDIR}/PLIST.pre >${PLIST_SRC}
	cd ${WRKDIR} && pax -rw -pp [a-z]* ${PREFIX}/${HTMLDIR}
	cd ${PREFIX} && find ${HTMLDIR} -type f -print >>${PLIST_SRC}

.include "../../mk/bsd.pkg.mk"
