# $NetBSD: Makefile,v 1.3 2014/04/02 19:08:31 nros Exp $

DISTNAME=	qore-mysql-module-2.0.1
PKGREVISION=	2
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=qore/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.qore.org/
COMMENT=	MySQL DB driver for Qore
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++
PTHREAD_OPTS+=	require

INSTALL_TARGET=	install install-html-local

.include "options.mk"

.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../wip/qore/buildlink3.mk"
.include "../../wip/qore/module.mk"
.include "../../mk/bsd.pkg.mk"
