# $NetBSD: Makefile,v 1.3 2004/03/25 18:34:17 marc Exp $

PKGNAME=	postgresql-${BASE_VERS}
COMMENT=	Robust, next generation, object-relational DBMS

DEPENDS+=	postgresql-client>=${BASE_VERS}:../../wip/postgresql74-client
DEPENDS+=	postgresql-server>=${BASE_VERS}:../../wip/postgresql74-server
DEPENDS+=	postgresql-docs>=${BASE_VERS}:../../wip/postgresql74-docs

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
