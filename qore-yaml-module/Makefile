# $NetBSD: Makefile,v 1.5 2014/04/03 13:11:03 nros Exp $

DISTNAME=	qore-yaml-module-0.4
PKGREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=   ${MASTER_SITE_SOURCEFORGE:=qore/}
EXTRACT_SUFX=   .tar.bz2

MAINTAINER=	nros@users.sourceforge.net
COMMENT=	Yaml module for Qore
HOMEPAGE=	http://www.qore.org/
LICENSE=	gnu-lgpl-v2.1 OR mit

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake

PTHREAD_OPTS+=	require

INSTALL_TARGET=	install install-html-local

#This is needed in order to comply the with MIT license and binary distribution
INSTALLATION_DIRS+=	share/qore/license/modules/yaml
post-install:
	${INSTALL_DATA} ${WRKSRC}/COPYING.LGPL \
		${DESTDIR}${PREFIX}/share/qore/license/modules/yaml
	${INSTALL_DATA} ${WRKSRC}/COPYING.MIT \
		${DESTDIR}${PREFIX}/share/qore/license/modules/yaml

.include "../../wip/qore/module.mk"
.include "options.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../textproc/libyaml/buildlink3.mk"
.include "../../wip/qore/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
