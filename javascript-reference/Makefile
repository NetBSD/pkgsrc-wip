# $NetBSD: Makefile,v 1.2 2005/07/27 16:25:54 thomasklausner Exp $
#

DISTNAME=		CoreReferenceJS15
PKGNAME=		javascript-reference-1.5
CATEGORIES=		misc
MASTER_SITES=		http://devedge.netscape.com/library/manuals/2000/javascript/1.5/reference/
EXTRACT_SUFX=		.zip

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://devedge.netscape.com/
COMMENT=		JavaScript Reference from Netscape Devedge

HTMLDIR=		share/doc/${PKGNAME}
NO_BIN_ON_CDROM=	"I am not sure if we can redistribute it"
NO_SRC_ON_CDROM=	"I am not sure if we can redistribute it"
NO_BUILD=		# defined

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/${HTMLDIR}
	${CAT} ${PKGDIR}/PLIST.pre >${PLIST_SRC}
	cd ${WRKDIR} && ${PAX} -rw -pe [a-z]* ${PREFIX}/${HTMLDIR}
	cd ${PREFIX} && ${FIND} ${HTMLDIR} -type f -print >>${PLIST_SRC}
	cd ${PREFIX} && ${FIND} -d ${HTMLDIR} -type d -print | \
	${SED} -e "s/^/@dirrm /" >>${PLIST_SRC}

.include "../../mk/bsd.pkg.mk"
