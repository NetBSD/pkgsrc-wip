# $NetBSD: Makefile,v 1.6 2006/05/19 16:51:19 ykomatsu Exp $
#

DISTNAME=		CoreGuideJS15
PKGNAME=		javascript-guide-1.5
CATEGORIES=		misc
MASTER_SITES=		http://devedge-temp.mozilla.org/library/manuals/2000/javascript/1.5/reference/
EXTRACT_SUFX=		.zip

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://devedge-temp.mozilla.org/
COMMENT=		JavaScript Guide from Netscape Devedge

HTMLDIR=		share/doc/${PKGNAME}
RESTRICTED=		I am not sure if we can redistribute it
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BUILD=		yes

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/${HTMLDIR}
	${CAT} ${PKGDIR}/PLIST.pre >${PLIST_SRC}
	cd ${WRKDIR} && ${PAX} -rw -pe [a-z]* ${PREFIX}/${HTMLDIR}
	cd ${PREFIX} && ${FIND} ${HTMLDIR} -type f -print >>${PLIST_SRC}
	cd ${PREFIX} && ${FIND} -d ${HTMLDIR} -type d -print | \
	${SED} -e "s/^/@dirrm /" >>${PLIST_SRC}

.include "../../mk/bsd.pkg.mk"
