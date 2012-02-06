# $NetBSD: Makefile,v 1.14 2012/02/06 20:15:18 fhajny Exp $
# $Id: Makefile,v 1.14 2012/02/06 20:15:18 fhajny Exp $

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

PKG_DESTDIR_SUPPORT=	user-destdir
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
