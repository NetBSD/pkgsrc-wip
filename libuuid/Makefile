# $NetBSD: Makefile,v 1.1.1.1 2004/01/10 18:05:25 mpasternak Exp $
# $Id: Makefile,v 1.1.1.1 2004/01/10 18:05:25 mpasternak Exp $

DISTNAME=		${E2FSPROGS_DISTNAME}
PKGNAME=		libuuid-1.34
WRKSRC=			${WRKDIR}/${DISTNAME}/lib/uuid/
CATEGORIES=		devel
MASTER_SITES=		${E2FSPROGS_MASTER_SITES}

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://e2fsprogs.sourceforge.net/
COMMENT=		Standalone libuuid from e2fsprogs package

CONFLICTS=		e2fsprogs-1.32

do-configure:
	cd ${WRKSRC}/../../ && ${SETENV} ${CONFIGURE_ENV} ./configure ${CONFIGURE_ARGS}
	
post-build:
	cd ${WRKSRC}/../../misc/ && ${SETENV} ${MAKE_ENV} ${MAKE} \
		${MAKE_FLAGS} uuidgen uuidgen.1

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/../../misc/uuidgen ${PREFIX}/bin/uuidgen
	${INSTALL_MAN} ${WRKSRC}/../../misc/uuidgen.1 ${PREFIX}/man/man1/uuidgen.1

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../wip/e2fsprogs/Makefile.common"
.include "../../mk/bsd.pkg.mk"
