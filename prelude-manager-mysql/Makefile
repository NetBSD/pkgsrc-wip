# $NetBSD: Makefile,v 1.1.1.1 2003/09/28 13:03:36 adrian_p Exp $

.include "../../wip/prelude-manager/Makefile.common"

PKGNAME=	${DISTNAME:S/-manger/-manager-mysql/}

COMMENT=	Prelude manager with MySQL support

CONFLICTS+=     prelude-manager-[0-9]*
CONFLICTS+=     prelude-manager-pgsql-[0-9]*

USE_BUILDLINK2=		YES

CONFIGURE_ARGS+=        --enable-mysql
CONFIGURE_ARGS+=        --disable-pgsql

PKGDIR=         ${.CURDIR}/../../wip/prelude-manager
FILESDIR=       ${PKGDIR}/files
PATCHDIR=       ${PKGDIR}/patches
DISTINFO_FILE=  ${PKGDIR}/distinfo
PLIST_SRC=      ${PKGDIR}/PLIST
PLIST_SRC+=     PLIST.mysql

.include "../../databases/mysql-client/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
