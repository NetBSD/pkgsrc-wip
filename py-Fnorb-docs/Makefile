# $NetBSD: Makefile,v 1.2 2005/07/27 16:27:21 thomasklausner Exp $
#

DISTNAME=		Fnorb-Guide.html
PKGNAME=		py-Fnorb-docs-0
WRKSRC=			${WRKDIR}/Fnorb-Guide
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=fnorb/}
EXTRACT_SUFX=		.tgz

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://fnorb.sourceforge.net/
COMMENT=		Documentation for py-Fnorb in HTML format

NO_CONFIGURE=	yes
NO_BUILD=	yes

HTMLDIR=	share/doc/${PKGNAME}
PLIST_SRC=	${WRKDIR}/.PLIST_SRC

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/${HTMLDIR}
	${CAT} ${PKGDIR}/PLIST.pre >${PLIST_SRC}
	cd ${WRKSRC} && ${PAX} -rw -pe * ${PREFIX}/${HTMLDIR}
	cd ${PREFIX} && ${FIND} ${HTMLDIR} -type f -print >>${PLIST_SRC}
	cd ${PREFIX} && ${FIND} -d ${HTMLDIR} -type d -print | \
	${SED} -e "s/^/@dirrm /" >>${PLIST_SRC}

.include "../../mk/bsd.pkg.mk"
