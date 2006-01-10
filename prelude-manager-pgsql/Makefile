# $NetBSD: Makefile,v 1.4 2006/01/10 12:45:12 ghen Exp $

.include "../../wip/prelude-manager/Makefile.common"

PKGNAME=	${DISTNAME:S/-manager/-manager-pgsql/}

COMMENT=	Prelude manager with PostgreSQL support

CONFLICTS+=	prelude-manager-[0-9]*
CONFLICTS+=	prelude-manager-mysql-[0-9]*

CONFIGURE_ARGS+=        --disable-mysql
CONFIGURE_ARGS+=        --enable-pgsql

PKGDIR=         ${.CURDIR}/../../wip/prelude-manager
FILESDIR=       ${PKGDIR}/files
PATCHDIR=       ${PKGDIR}/patches
DISTINFO_FILE=  ${PKGDIR}/distinfo
PLIST_SRC=	${PKGDIR}/PLIST
PLIST_SRC+=	PLIST.pgsql

.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
