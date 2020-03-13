# $NetBSD: Makefile,v 1.6 2014/10/10 14:06:04 fhajny Exp $
#

DISTNAME=	mysql-proxy-0.8.5
PKGNAME=	${DISTNAME:S/mysql/mysql${_MYSQL_VERSION}/}
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_MYSQL:=MySQL-Proxy/}

MAINTAINER=	fhajny@NetBSD.org
HOMEPAGE=	http://dev.mysql.com/downloads/mysql-proxy/
COMMENT=	Monitor, analyze, or transform the communication of MySQL
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

LUA_VERSIONS_ACCEPTED=		51
MYSQL_VERSIONS_ACCEPTED=	56 55

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	flex pkg-config

PKGCONFIG_OVERRIDE+=	mysql-chassis.pc.in
PKGCONFIG_OVERRIDE+=	mysql-proxy.pc.in

.include "../../mk/bsd.fast.prefs.mk"

.if ${OPSYS} == "SunOS"
CONFIGURE_ARGS+=	--enable-dtrace
.endif
CONFIGURE_ARGS+=	--enable-self-contained
CONFIGURE_ARGS+=	--with-lua

LDFLAGS.SunOS+=	-lnsl -lsocket

post-extract:
	cd ${WRKSRC} && ${LN} -sf ../../suite/lua-tests-wrapper.sh.in \
	  tests/unit/lua/lua-tests-wrapper.sh.in

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libevent/buildlink3.mk"
.include "../../lang/lua/buildlink3.mk"
.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
