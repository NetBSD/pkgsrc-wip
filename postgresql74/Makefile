# $NetBSD: Makefile,v 1.2 2004/03/20 22:26:51 marc Exp $

PKGNAME=	postgresql-${BASE_VERS}
COMMENT=	Robust, next generation, object-relational DBMS

DEPENDS+=	postgresql-client>=${BASE_VERS}:../../wip/postgresql-client
DEPENDS+=	postgresql-server>=${BASE_VERS}:../../wip/postgresql-server
DEPENDS+=	postgresql-docs>=${BASE_VERS}:../../wip/postgresql-docs

PLIST_SRC=	${.CURDIR}/../../databases/postgresql/PLIST
DESCR_SRC=	${.CURDIR}/../../databases/postgresql/DESCR

.include "Makefile.common"

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	YES
NO_CONFIGURE=	YES
NO_BUILD=	YES

do-install:	# empty
do-patch:	# empty

.include "../../mk/bsd.pkg.mk"
