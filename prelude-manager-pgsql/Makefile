# $NetBSD: Makefile,v 1.3 2004/07/25 16:22:58 marc Exp $

.include "../../wip/prelude-manager/Makefile.common"

PKGNAME=	${DISTNAME:S/-manager/-manager-pgsql/}

COMMENT=	Prelude manager with PostgreSQL support

CONFLICTS+=	prelude-manager-[0-9]*
CONFLICTS+=	prelude-manager-mysql-[0-9]*

DEPENDS+=	postgresql73-client>=7.3.4:../../databases/postgresql73-client

CONFIGURE_ARGS+=        --disable-mysql
CONFIGURE_ARGS+=        --enable-pgsql

PKGDIR=         ${.CURDIR}/../../wip/prelude-manager
FILESDIR=       ${PKGDIR}/files
PATCHDIR=       ${PKGDIR}/patches
DISTINFO_FILE=  ${PKGDIR}/distinfo
PLIST_SRC=	${PKGDIR}/PLIST
PLIST_SRC+=	PLIST.pgsql

.include "../../databases/postgresql73-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
