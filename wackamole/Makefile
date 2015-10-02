# $NetBSD: Makefile,v 1.2 2013/07/26 11:58:45 fhajny Exp $

DISTNAME=	wackamole-2.1.4
CATEGORIES=	net
MASTER_SITES=	http://mirrors.omniti.com/wackamole/

MAINTAINER=	filip@joyent.com
HOMEPAGE=	http://www.backhand.org/wackamole/
COMMENT=	Peer-to-peer high availability cluster
#LICENSE=	# TODO: (see mk/license.mk)

GNU_CONFIGURE=		yes
USE_TOOLS+=		flex yacc

USE_GCC_RUNTIME=	yes

.include "../../mk/bsd.fast.prefs.mk"

BUILD_DEFS+=		VARBASE WACKAMOLE_PID_DIR
WACKAMOLE_PID_DIR?=	${VARBASE}/run/wackamole

CONFIGURE_ARGS+=	--with-pid-dir=${WACKAMOLE_PID_DIR}

CONF_FILES+=	share/examples/wackamole/wackamole.conf \
		${PKG_SYSCONFDIR}/wackamole.conf

.include "../../net/spread/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
