# $NetBSD: Makefile,v 1.6 2014/10/23 18:59:18 nros Exp $

DISTNAME=	qore-opengl-module-0.0.3
PKGREVISION=	3
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
PTHREAD_OPTS+=	native

CONFIGURE_ARGS+=--with-opengl=${BUILDLINK_PREFIX.MesaLib}

INSTALLATION_DIRS+=     share/doc/${PKGBASE}
post-install:
	${INSTALL_DATA} ${WRKSRC}/docs/opengl-module-doc.html \
		${DESTDIR}${PREFIX}/share/doc/${PKGBASE}

.include "options.mk"

.include "../../graphics/glu/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../wip/qore/buildlink3.mk"
.include "../../wip/qore/module.mk"
.include "../../mk/bsd.pkg.mk"
