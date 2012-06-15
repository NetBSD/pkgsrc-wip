# $NetBSD: Makefile,v 1.6 2012/06/15 11:33:28 fhajny Exp $
#

DISTNAME=	node-v0.7.10
CATEGORIES=	devel
MASTER_SITES=	http://nodejs.org/dist/${DISTNAME:S/node-//}/
PKGNAME=	${DISTNAME:S/-v/js-/}

MAINTAINER=	msporleder@gmail.com
HOMEPAGE=	http://nodejs.org/
COMMENT=	V8 JavaScript for clients and servers
LICENSE=	mit

PKG_DESTDIR_SUPPORT=	user-destdir
CHECK_INTERPRETER=	no

HAS_CONFIGURE=	yes
USE_TOOLS+=	pkg-config
USE_TOOLS+=	gmake
USE_LANGUAGES=	c c++

.include "../../mk/bsd.prefs.mk"
.include "options.mk"

.if ${OPSYS} == "NetBSD" || ${OPSYS} == "FreeBSD" || ${OPSYS} == "OpenBSD"
DEPENDS+=		libexecinfo>=1:../../wip/libexecinfo
.endif

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

SUBST_CLASSES+=		python
SUBST_STAGE.python=	post-patch
SUBST_MESSAGE.python=	Fixing Python references
SUBST_FILES.python=	deps/v8/tools/gyp/v8.gyp
SUBST_VARS.python=	PYTHONBIN

CONFIG_SHELL=		${PYTHONBIN}
CONFIGURE_ARGS+=	--prefix=${PREFIX}

.if ${OPSYS} == "NetBSD"
CONFIGURE_ENV+=		GYP_DEFINES="OS=netbsd"
.endif

REPLACE_PYTHON+=	configure
REPLACE_PYTHON+=	tools/gyp_node
REPLACE_PYTHON+=	tools/node-waf
REPLACE_PYTHON+=	tools/waf-light
REPLACE_PYTHON+=	tools/wafadmin/*.py
REPLACE_PYTHON+=	tools/wafadmin/Tools/*.py

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
