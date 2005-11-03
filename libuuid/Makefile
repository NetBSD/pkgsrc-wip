# $NetBSD: Makefile,v 1.7 2005/11/03 15:32:26 rillig Exp $
# $Id: Makefile,v 1.7 2005/11/03 15:32:26 rillig Exp $

.include "../../wip/e2fsprogs/Makefile.common"

DISTNAME=		${E2FSPROGS_DISTNAME}
PKGNAME=		libuuid-${E2FSPROGS_VERSION}
CATEGORIES=		devel
MASTER_SITES=		${E2FSPROGS_MASTER_SITES}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://e2fsprogs.sourceforge.net/
COMMENT=		Standalone libuuid from e2fsprogs package

DISTINFO_FILE=		${.CURDIR}/distinfo

CONFLICTS=		e2fsprogs-1.32 e2fsprogs-1.36
BUILD_DIRS=		lib/uuid
PKGCONFIG_OVERRIDE+=    uuid.pc.in

post-build:
	cd ${WRKSRC}/misc && ${SETENV} ${MAKE_ENV} ${MAKE} \
		${MAKE_FLAGS} uuidgen uuidgen.1

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/misc/uuidgen ${PREFIX}/bin/uuidgen
	${INSTALL_MAN} ${WRKSRC}/misc/uuidgen.1 ${PREFIX}/man/man1/uuidgen.1

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
