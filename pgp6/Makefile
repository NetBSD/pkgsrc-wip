# $NetBSD: Makefile,v 1.6 2004/12/02 16:39:04 thomasklausner Exp $
#

DISTNAME=		pgpsrc658unix
PKGNAME=		pgp6-6.5.8
WRKSRC=			${WRKDIR}/pgpsrc
CATEGORIES=		security
.for C in no ch cz de dk es fi hu nl ru ua
MASTER_SITES+=		ftp://ftp.$C.pgpi.org/pub/pgp/${PKGVERSION:R}/${PKGVERSION}/
.endfor

MAINTAINER=		tv@duh.org
HOMEPAGE=		http://www.pgpi.org/products/pgp/versions/freeware/unix/6.5.8/
COMMENT=		Public-key encryption and digital signature utilities (v6)

GNU_CONFIGURE=		yes
USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make

buildDIRS=		libs/pfl libs/pgpcdk clients/pgp/shared clients/pgp/cmdline

BUILD_TARGET=		headers all
CONFIGURE_DIRS=		${buildDIRS:C|^|${WRKSRC}/|}
BUILD_DIRS=		${buildDIRS:C|^|${WRKSRC}/|}
MAKE_FLAGS+=		DEBUG=0 LDAP_DEBUG=

.include "../../mk/bsd.prefs.mk"

CPPFLAGS+=		-D__unix__

post-extract:
	cd ${WRKDIR} && extract_file=pgpsrc658unix.tar.gz && ${EXTRACT_CMD.tar.gz}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/clients/pgp/cmdline/pgp ${PREFIX}/bin/pgp6
	${INSTALL_DATA} ${WRKSRC}/clients/pgp/cmdline/packaging/pgp-6.0/man/man1/pgp.1 ${PREFIX}/man/man1/pgp6.1
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/pgp6
	${INSTALL_DATA} ${WRKSRC}/clients/pgp/cmdline/packaging/pgp-6.0/docs/* ${PREFIX}/share/doc/pgp6/

.include "../../mk/bsd.pkg.mk"
