# $NetBSD: Makefile,v 1.3 2008/02/06 17:02:34 hoka_adam Exp $

DISTNAME=		pkg_rmleaves-20050922
CATEGORIES=		pkgtools
MASTER_SITES=		http://utenti.gufi.org/~drizzt/codes/ports/pkg_rmleaves/

MAINTAINER=		ghen@NetBSD.org
COMMENT=		Interactive script for deinstalling 'leaf' packages
HOMEPAGE=		#

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}/pkg_rmleaves
NO_BUILD=		yes

DEPENDS+=		dialog>=1:../../misc/dialog

SUBST_CLASSES+=		dbdir
SUBST_STAGE.dbdir=	post-patch
SUBST_FILES.dbdir=	pkg_rmleaves
SUBST_SED.dbdir=	-e 's,/var/db/pkg,${PKG_DBDIR},g'

INSTALLATION_DIRS+=	sbin ${PKGMANDIR}/man1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/pkg_rmleaves ${DESTDIR}${PREFIX}/sbin/
	${INSTALL_MAN} ${WRKSRC}/pkg_rmleaves.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/

.include "../../mk/bsd.pkg.mk"
