# $NetBSD: Makefile,v 1.1.1.1 2003/08/20 08:55:21 jeremy-c-reed Exp $

DISTNAME=		man-db-${VERSION}
CATEGORIES=		misc
MASTER_SITES=		http://savannah.nongnu.org/download/man-db/stable.pkg/${VERSION}/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.chiark.greenend.org.uk/~cjwatson/code/man-db/
COMMENT=		man pager and related man page utilities

.if !exists(/usr/bin/nroff)
DEPENDS+=		groff-[0-9]*:../../textproc/groff
.endif

.if !exists(/usr/bin/yacc)
BUILD_DEPENDS+=         bison-[0-9]*:../../devel/bison
.endif

VERSION=		2.4.1

# for modifying cat and database files
MAN_DB_USER?=		man-db
PKG_USERS=		${MAN_DB_USER}:${ROOT_GROUP}::man-db\\ user
USE_PKGINSTALL=		YES

USE_BUILDLINK2=		YES
USE_PKGLOCALEDIR=	YES
GNU_CONFIGURE=		YES
USE_GMAKE=		YES
MAKEFILE=		GNUmakefile
CONFIGURE_ARGS+=	--mandir=${PREFIX}/man
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFBASE}
CONFIGURE_ARGS+=	--enable-setuid=${MAN_DB_USER}

CONF_FILES=		${PREFIX}/share/examples/man-db/man_db.conf ${PKG_SYSCONFDIR}/man_db.conf

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/man-db
	${INSTALL_DATA} ${WRKSRC}/src/man_db.conf ${PREFIX}/share/examples/man-db

.include "../../databases/db/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
