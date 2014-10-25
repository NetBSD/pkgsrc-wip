# $NetBSD: Makefile,v 1.6 2014/10/25 14:49:09 nros Exp $

DISTNAME=	qore-mysql-module-2.0.1
PKGREVISION=	4
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=qore/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	nros@users.sourceforge.net
HOMEPAGE=	http://www.qore.org/
COMMENT=	MySQL DB driver for Qore
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++
PTHREAD_OPTS+=	native

#install docs
INSTALLATION_DIRS+=	share/doc/${PKGBASE}
post-install:
	${CP} -R ${WRKSRC}/docs/mysql/html \
		${DESTDIR}${PREFIX}/share/doc/${PKGBASE}

.include "options.mk"

.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../wip/qore/buildlink3.mk"
.include "../../wip/qore/module.mk"
.include "../../mk/bsd.pkg.mk"
