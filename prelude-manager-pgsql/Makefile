# $NetBSD: Makefile,v 1.1.1.1 2003/09/28 13:03:13 adrian_p Exp $

.include "../../wip/prelude-manager/Makefile.common"

PKGNAME=	${DISTNAME:S/-manager/-manager-pgsql/}

COMMENT=	Prelude manager with PostgreSQL support

CONFLICTS+=	prelude-manager-[0-9]*
CONFLICTS+=	prelude-manager-mysql-[0-9]*

USE_BUILDLINK2=		YES

DEPENDS+=	postgresql-client>=7.3.4:../../databases/postgresql-client

CONFIGURE_ARGS+=        --disable-mysql
CONFIGURE_ARGS+=        --enable-pgsql

PKGDIR=         ${.CURDIR}/../../wip/prelude-manager
FILESDIR=       ${PKGDIR}/files
PATCHDIR=       ${PKGDIR}/patches
DISTINFO_FILE=  ${PKGDIR}/distinfo
PLIST_SRC=	${PKGDIR}/PLIST
PLIST_SRC+=	PLIST.pgsql

.include "../../databases/postgresql-lib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
