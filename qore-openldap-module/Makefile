# $NetBSD: Makefile,v 1.6 2014/10/25 14:54:07 nros Exp $

DISTNAME=	qore-openldap-module-1.0
PKGREVISION=	4
CATEGORIES=	databases
MASTER_SITES=   ${MASTER_SITE_SOURCEFORGE:=qore/}
EXTRACT_SUFX=   .tar.bz2

MAINTAINER=	nros@users.sourceforge.net
COMMENT=	Openldap module for Qore
HOMEPAGE=	http://www.qore.org/
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake
PTHREAD_OPTS+=	native

#install docs
INSTALLATION_DIRS+=share/doc/${PKGBASE}
post-install:
	${CP} -R ${WRKSRC}/docs/openldap/html \
		${DESTDIR}${PREFIX}/share/doc/${PKGBASE}

.include "options.mk"

.include "../../databases/openldap-client/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../wip/qore/buildlink3.mk"
.include "../../wip/qore/module.mk"
.include "../../mk/bsd.pkg.mk"
