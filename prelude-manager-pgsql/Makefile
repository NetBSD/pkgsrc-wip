# $NetBSD: Makefile,v 1.2 2004/05/10 01:20:37 blef Exp $

.include "../../wip/prelude-manager/Makefile.common"

PKGNAME=	${DISTNAME:S/-manager/-manager-pgsql/}

COMMENT=	Prelude manager with PostgreSQL support

CONFLICTS+=	prelude-manager-[0-9]*
CONFLICTS+=	prelude-manager-mysql-[0-9]*

DEPENDS+=	postgresql-client>=7.3.4:../../databases/postgresql-client

CONFIGURE_ARGS+=        --disable-mysql
CONFIGURE_ARGS+=        --enable-pgsql

PKGDIR=         ${.CURDIR}/../../wip/prelude-manager
FILESDIR=       ${PKGDIR}/files
PATCHDIR=       ${PKGDIR}/patches
DISTINFO_FILE=  ${PKGDIR}/distinfo
PLIST_SRC=	${PKGDIR}/PLIST
PLIST_SRC+=	PLIST.pgsql

.include "../../databases/postgresql-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
