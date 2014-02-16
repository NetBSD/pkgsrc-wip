# $NetBSD: Makefile,v 1.2 2014/02/16 15:56:54 nros Exp $

DISTNAME=	qore-opengl-module-0.0.3
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
.include "../../mk/bsd.pkg.mk"
