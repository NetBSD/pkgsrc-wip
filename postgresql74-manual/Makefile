# $NetBSD: Makefile,v 1.1.1.1 2004/03/15 14:59:26 mpasternak Exp $
# $Id: Makefile,v 1.1.1.1 2004/03/15 14:59:26 mpasternak Exp $
#

PKGNAME=		postgresql74-manual-${BASE_VERS}
SVR4_PKGNAME=		pstgm
COMMENT=		PostgreSQL database system manual

.include "../../wip/postgresql74/Makefile.common"

BUILD_DIRS=		${WRKSRC}/doc
DOCDIR=			${PREFIX}/share/doc/postgresql/manual
DESCR_SRC=		${.CURDIR}/../../databases/postgresql-docs/DESCR

DEPENDS+=		postgresql74-docs>=${BASE_VERS}:../../wip/postgresql-docs

NO_BUILD=		# defined
NO_CONFIGURE=		# defined

do-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	cd ${DOCDIR} && ${TAR} -xzvf ${WRKSRC}/doc/postgres.tar.gz

.include "../../mk/bsd.pkg.mk"
