# $NetBSD: Makefile,v 1.5 2014/10/23 18:47:56 nros Exp $

DISTNAME=	qore-sybase-modules-1.0.3
PKGNAME=	${DISTNAME:S/sybase-modules/freetds-module/}
PKGREVISION=	3
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=qore/}

MAINTAINER=	nros@users.sourceforge.net
HOMEPAGE=	http://www.qore.org/
COMMENT=	Freetds DB driver for qore
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++
PTHREAD_OPTS+=	require

CONFIGURE_ARGS+=--with-sybase=no

INSTALLATION_DIRS+=     share/doc/qore-freetds-module
post-install:
	${INSTALL_DATA} ${WRKSRC}/docs/sybase-module-doc.html \
	${DESTDIR}${PREFIX}/share/doc/qore-freetds-module/freetds-module-doc.html

.include "options.mk"

.include "../../databases/freetds/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../wip/qore/buildlink3.mk"
.include "../../wip/qore/module.mk"
.include "../../mk/bsd.pkg.mk"
