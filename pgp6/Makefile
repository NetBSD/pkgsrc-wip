# $NetBSD: Makefile,v 1.10 2005/10/10 13:41:09 rillig Exp $
#

DISTNAME=		pgpsrc658unix
PKGNAME=		pgp6-6.5.8
CATEGORIES=		security
.for C in no ch cz de dk es fi hu nl ru ua
MASTER_SITES+=		ftp://ftp.${C}.pgpi.org/pub/pgp/6.5/6.5.8/
.endfor

MAINTAINER=		tv@duh.org
HOMEPAGE=		http://www.pgpi.org/products/pgp/versions/freeware/unix/6.5.8/
COMMENT=		Public-key encryption and digital signature utilities (v6)

WRKSRC=			${WRKDIR}/pgpsrc
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake

BUILD_TARGET=		headers all
CONFIGURE_DIRS=		libs/pfl libs/pgpcdk clients/pgp/shared clients/pgp/cmdline
BUILD_DIRS=		${CONFIGURE_DIRS}
MAKE_FLAGS+=		DEBUG=0 LDAP_DEBUG=

.include "../../mk/bsd.prefs.mk"

CPPFLAGS+=		-D__unix__

# The DISTFILE is doubly packed.
post-extract:
	cd ${WRKDIR} && extract_file=pgpsrc658unix.tar.gz && ${EXTRACT_CMD.tar.gz}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/clients/pgp/cmdline/pgp ${PREFIX}/bin/pgp6
	${INSTALL_DATA} ${WRKSRC}/clients/pgp/cmdline/packaging/pgp-6.0/man/man1/pgp.1 ${PREFIX}/man/man1/pgp6.1
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/pgp6
	${INSTALL_DATA} ${WRKSRC}/clients/pgp/cmdline/packaging/pgp-6.0/docs/* ${PREFIX}/share/doc/pgp6/

.include "../../mk/bsd.pkg.mk"
