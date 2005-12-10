# $NetBSD: Makefile,v 1.1.1.1 2005/12/10 12:55:30 ghen Exp $

DISTNAME=		pkg_rmleaves-20050922
CATEGORIES=		pkgtools
MASTER_SITES=		http://utenti.gufi.org/~drizzt/codes/ports/pkg_rmleaves/

MAINTAINER=		geert.hendrickx@ua.ac.be
COMMENT=		Interactive script for deinstalling 'leaf' packages
HOMEPAGE=		#

WRKSRC=			${WRKDIR}/pkg_rmleaves
NO_BUILD=		yes

DEPENDS+=		dialog>=1:../../misc/dialog

SUBST_CLASSES+=		dbdir
SUBST_STAGE.dbdir=	post-patch
SUBST_FILES.dbdir=	pkg_rmleaves
SUBST_SED.dbdir=	-e 's,/var/db/pkg,${PKG_DBDIR},g'

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/pkg_rmleaves ${PREFIX}/sbin/
	${INSTALL_MAN} ${WRKSRC}/pkg_rmleaves.1 ${PREFIX}/${PKGMANDIR}/man1/

.include "../../mk/bsd.pkg.mk"
