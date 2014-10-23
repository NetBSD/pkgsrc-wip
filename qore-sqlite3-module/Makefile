# $NetBSD: Makefile,v 1.7 2014/10/23 19:08:49 nros Exp $

DISTNAME=	qore-sqlite3-module-1.0.1
PKGREVISION=	3
CATEGORIES=	databases
MASTER_SITES=   ${MASTER_SITE_SOURCEFORGE:=qore/}

MAINTAINER=	nros@users.sourceforge.net
HOMEPAGE=	http://www.qore.org/
COMMENT=	SQLite module for Qore
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++
PTHREAD_OPTS+=	native

CONFIGURE_ARGS+=--with-sqlite3=${BUILDLINK_PREFIX.sqlite3}

INSTALLATION_DIRS+=     share/doc/${PKGBASE}
post-install:
	${INSTALL_DATA} ${WRKSRC}/docs/sqlite3-module-doc.html \
		${DESTDIR}${PREFIX}/share/doc/${PKGBASE}

.include "options.mk"

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../wip/qore/buildlink3.mk"
.include "../../wip/qore/module.mk"
.include "../../mk/bsd.pkg.mk"
