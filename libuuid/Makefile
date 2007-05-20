# $NetBSD: Makefile,v 1.12 2007/05/20 03:08:24 kheinz Exp $
# $Id: Makefile,v 1.12 2007/05/20 03:08:24 kheinz Exp $

.include "../../wip/e2fsprogs/Makefile.common"

DISTNAME=		${E2FSPROGS_DISTNAME}
PKGNAME=		libuuid-${E2FSPROGS_VERSION}
CATEGORIES=		devel
MASTER_SITES=		${E2FSPROGS_MASTER_SITES}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://e2fsprogs.sourceforge.net/
COMMENT=		Standalone libuuid from e2fsprogs package

DISTINFO_FILE=		${.CURDIR}/distinfo

CONFLICTS=		e2fsprogs-1.32 e2fsprogs-1.36
CONFLICTS+=		ossp-uuid-[0-9]* # libuuid.* uuid.pc uuid.3
BUILD_DIRS=		lib/uuid
PKGCONFIG_OVERRIDE+=	lib/uuid/uuid.pc.in

post-build:
	cd ${WRKSRC:Q}/misc && ${SETENV} ${MAKE_ENV} ${MAKE} \
		${MAKE_FLAGS} uuidgen uuidgen.1

post-install:
	${INSTALL_PROGRAM} ${WRKSRC:Q}/misc/uuidgen ${PREFIX:Q}/bin/uuidgen
	${INSTALL_MAN} ${WRKSRC:Q}/misc/uuidgen.1 ${PREFIX:Q}/${PKGMANDIR}/man1/uuidgen.1

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
