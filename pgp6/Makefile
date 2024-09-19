# $NetBSD: Makefile,v 1.15 2012/10/05 11:07:45 asau Exp $
#

DISTNAME=		pgpsrc658unix
PKGNAME=		pgp6-6.5.8
CATEGORIES=		security
.for C in no ch cz de dk es fi hu nl ru ua
MASTER_SITES+=		ftp://ftp.${C}.pgpi.org/pub/pgp/6.5/6.5.8/
.endfor

MAINTAINER=		pkgsrc-wip-discuss@lists.sourceforge.net
HOMEPAGE=		http://www.pgpi.org/products/pgp/versions/freeware/unix/6.5.8/
COMMENT=		Public-key encryption and digital signature utilities (v6)

WRKSRC=			${WRKDIR}/pgpsrc
GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake

BUILD_TARGET=		headers all
CONFIGURE_DIRS=		libs/pfl libs/pgpcdk clients/pgp/shared clients/pgp/cmdline
BUILD_DIRS=		${CONFIGURE_DIRS}
MAKE_FLAGS+=		DEBUG=0 LDAP_DEBUG=

.include "../../mk/bsd.prefs.mk"

CPPFLAGS+=		-D__unix__

# The DISTFILE is doubly packed.
post-extract:
	cd ${WRKDIR} && extract_file=pgpsrc658unix.tar.gz && ${EXTRACT_CMD}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/clients/pgp/cmdline/pgp ${DESTDIR}${PREFIX}/bin/pgp6
	${INSTALL_DATA} ${WRKSRC}/clients/pgp/cmdline/packaging/pgp-6.0/man/man1/pgp.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/pgp6.1
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/pgp6
	${INSTALL_DATA} ${WRKSRC}/clients/pgp/cmdline/packaging/pgp-6.0/docs/* ${DESTDIR}${PREFIX}/share/doc/pgp6/

.include "../../mk/bsd.pkg.mk"
