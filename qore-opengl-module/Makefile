# $NetBSD: Makefile,v 1.4 2014/04/02 19:25:58 nros Exp $

DISTNAME=	qore-opengl-module-0.0.3
PKGREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=qore/}

MAINTAINER=	nros@users.sourceforge.net
HOMEPAGE=	http://www.qore.org/
COMMENT=	OpenGL Qore bindings
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake

CONFIGURE_ARGS+=--with-opengl=${BUILDLINK_PREFIX.MesaLib}

INSTALLATION_DIRS+=     share/qore/docs/modules/opengl/html
post-install:
	${INSTALL_DATA} ${WRKSRC}/docs/opengl-module-doc.html \
		${DESTDIR}${PREFIX}/share/qore/docs/modules/opengl/html

.include "options.mk"

.include "../../graphics/glu/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../wip/qore/buildlink3.mk"
.include "../../wip/qore/module.mk"
.include "../../mk/bsd.pkg.mk"
