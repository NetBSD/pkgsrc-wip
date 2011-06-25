# $NetBSD: Makefile,v 1.4 2011/06/25 12:44:55 genolopolis Exp $
#

DISTNAME=	node-v0.4.7
CATEGORIES=	wip
MASTER_SITES=	http://nodejs.org/dist/
PKGNAME=	${DISTNAME:S/-v/js-/}

MAINTAINER=	msporleder@gmail.com
HOMEPAGE=	http://nodejs.org/
COMMENT=	V8 JavaScript for clients and servers
LICENSE=	mit

PKG_DESTDIR_SUPPORT=	user-destdir

HAS_CONFIGURE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	tools/nodejs.pc.in

.include "../../mk/bsd.prefs.mk"
.include "options.mk"
DEPENDS+=		libexecinfo>=1:../../wip/libexecinfo
BUILD_DEPENDS+=		scons>=1:../../devel/scons
PYTHON_FOR_BUILD_ONLY=	yes

NODE_USER?=		node
NODE_GROUP?=		node
NODE_HOME?=		${HOMEBASE}/${NODE_USER}
PKG_GROUPS+=		${NODE_GROUP}
PKG_USERS+=		${NODE_USER}:${NODE_GROUP}
PKG_GECOS.${NODE_USER}=	Node daemon user
PKG_HOME.${NODE_USER}=	${NODE_HOME}
PKG_SHELL.${NODE_USER}=	${COMMAND_SHELL}

OWN_DIRS+=		${NODE_HOME}
OWN_DIRS_PERMS+=	${NODE_HOME} ${NODE_USER} ${NODE_GROUP} 0750

post-extract:
	cp -r ${WRKSRC}/deps/c-ares/openbsd-x64 ${WRKSRC}/deps/c-ares/netbsd-x64
	cp -r ${WRKSRC}/deps/c-ares/openbsd-ia32 ${WRKSRC}/deps/c-ares/netbsd-ia32

REPLACE_PYTHON+=	tools/waf-light
REPLACE_PYTHON+=	tools/node-waf
REPLACE_PYTHON+=	tools/wafadmin/*.py
REPLACE_PYTHON+=	tools/wafadmin/Tools/*.py

.include "../../lang/python26/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
