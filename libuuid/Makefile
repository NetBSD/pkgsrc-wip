# $NetBSD: Makefile,v 1.15 2012/10/03 09:10:41 asau Exp $
# $Id: Makefile,v 1.15 2012/10/03 09:10:41 asau Exp $

.include "../../wip/e2fsprogs/Makefile.common"

DISTNAME=		${E2FSPROGS_DISTNAME}
PKGNAME=		libuuid-${E2FSPROGS_VERSION}
CATEGORIES=		devel
MASTER_SITES=		${E2FSPROGS_MASTER_SITES}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://e2fsprogs.sourceforge.net/
COMMENT=		Standalone libuuid from e2fsprogs package
LICENSE=		modified-bsd

DISTINFO_FILE=		${.CURDIR}/distinfo

AUTO_MKDIRS=		yes

CONFLICTS=		e2fsprogs-1.32{,nb*} e2fsprogs-1.36{,nb*}
CONFLICTS+=		ossp-uuid-[0-9]* # libuuid.* uuid.pc uuid.3
BUILD_DIRS=		lib/uuid
PKGCONFIG_OVERRIDE+=	lib/uuid/uuid.pc.in

post-build:
	cd ${WRKSRC}/misc && ${SETENV} ${MAKE_ENV} ${MAKE} \
		${MAKE_FLAGS} uuidgen uuidgen.1

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/misc/uuidgen ${DESTDIR}${PREFIX}/bin/uuidgen
	${INSTALL_MAN} ${WRKSRC}/misc/uuidgen.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/uuidgen.1

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
