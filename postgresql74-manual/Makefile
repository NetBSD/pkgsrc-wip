# $NetBSD: Makefile,v 1.2 2004/03/20 22:26:52 marc Exp $
# $Id: Makefile,v 1.2 2004/03/20 22:26:52 marc Exp $
#

PKGNAME=		postgresql-manual-${BASE_VERS}
SVR4_PKGNAME=		pstgm
COMMENT=		PostgreSQL database system manual

.include "../../wip/postgresql74/Makefile.common"

BUILD_DIRS=		${WRKSRC}/doc
DOCDIR=			${PREFIX}/share/doc/postgresql/manual
DESCR_SRC=		${.CURDIR}/../../databases/postgresql-docs/DESCR

DEPENDS+=		postgresql-docs>=${BASE_VERS}:../../wip/postgresql-docs

NO_BUILD=		# defined
NO_CONFIGURE=		# defined

do-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	cd ${DOCDIR} && ${TAR} -xzvf ${WRKSRC}/doc/postgres.tar.gz

.include "../../mk/bsd.pkg.mk"
