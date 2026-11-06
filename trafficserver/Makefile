# $NetBSD$

DISTNAME=	trafficserver-10.2.1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=apache/}

MAINTAINER=	andrew@pmk1.net
HOMEPAGE=	https://github.com/apache/trafficserver
COMMENT=	Apache Trafficserver
LICENSE=	modified-bsd
DEPENDS+=	daemonize>=1.3:../../sysutils/daemonize

USE_CXX_FEATURES=	c++17
USE_LANGUAGES=		c c++
USE_TOOLS+=		pkg-config

CFLAGS+=		-fPIC
CMAKE_CONFIGURE_ARGS+=	-DENABLE_JEMALLOC=ON
CMAKE_CONFIGURE_ARGS+=	-DEXTERNAL_YAML_CPP=ON
CMAKE_CONFIGURE_ARGS+=	-DBUILD_EXPERIMENTAL_PLUGINS=ON
CMAKE_CONFIGURE_ARGS+=	-DLIBLZMA_INCLUDE_DIR:PATH=${BUILDLINK_PREFIX.xz}/include
CMAKE_CONFIGURE_ARGS+=	-DLIBLZMA_LIBRARY:FILEPATH=${BUILDLINK_PREFIX.xz}/lib/liblzma.so
CMAKE_CONFIGURE_ARGS+=	-DWITH_GROUP:STRING=trafficserver
CMAKE_CONFIGURE_ARGS+=	-DWITH_USER:STRING=trafficserver
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_INSTALL_LOGDIR:STRING=/var/log/trafficserver
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_INSTALL_RUNSTATEDIR:STRING=/var/run/trafficserver

RCD_SCRIPTS+=	trafficserver
TRAFUSER?=	trafficserver
TRAFGROUP?=	${TRAFUSER}
TRAFLOGDIR=	/var/log/trafficserver
TRAFSTATEDIR=	/var/run/trafficserver

MAKE_DIRS+=		${TRAFLOGDIR}
MAKE_DIRS+=		${TRAFSTATEDIR}
MAKE_DIRS_PERMS+=	${TRAFLOGDIR} ${TRAFUSER} ${TRAFGROUP} 0775
MAKE_DIRS_PERMS+=	${TRAFSTATEDIR} ${TRAFUSER} ${TRAFGROUP} 0775

PKG_GROUPS+=		${TRAFGROUP}
PKG_USERS+=		${TRAFUSER}:${TRAFGROUP}
PKG_HOME.${TRAFUSER}=	/home/nonexistent
PKG_SHELL.${TRAFUSER}=	${SH}
PKG_GECOS.${TRAFUSER}=	Trafficserver daemon user

EGDIR=		${PREFIX}/share/examples/${PKGBASE}
MAKE_DIRS+=	${PKG_SYSCONFDIR}/trafficserver
CONF_FILES+=	${PREFIX}/share/examples/trafficserver/body_factory/default/.body_factory_info \
		${PKG_SYSCONFDIR}/trafficserver/body_factory/default/.body_factory_info
CONF_FILES+=	${PREFIX}/share/examples/trafficserver/body_factory/default/README \
		${PKG_SYSCONFDIR}/trafficserver/body_factory/default/README
CONF_FILES+=	${PREFIX}/share/examples/trafficserver/body_factory/default/access\#denied \
		${PKG_SYSCONFDIR}/trafficserver/body_factory/default/access\#denied
CONF_FILES+=	${PREFIX}/share/examples/trafficserver/body_factory/default/access\#proxy_auth_required \
		${PKG_SYSCONFDIR}/trafficserver/body_factory/default/access\#proxy_auth_required
CONF_FILES+=	${PREFIX}/share/examples/trafficserver/body_factory/default/access\#ssl_forbidden \
		${PKG_SYSCONFDIR}/trafficserver/body_factory/default/access\#ssl_forbidden
CONF_FILES+=	${PREFIX}/share/examples/trafficserver/body_factory/default/cache\#not_in_cache \
		${PKG_SYSCONFDIR}/trafficserver/body_factory/default/cache\#not_in_cache
CONF_FILES+=	${PREFIX}/share/examples/trafficserver/body_factory/default/cache\#read_error \
		${PKG_SYSCONFDIR}/trafficserver/body_factory/default/cache\#read_error
CONF_FILES+=	${PREFIX}/share/examples/trafficserver/body_factory/default/connect\#all_down \
		${PKG_SYSCONFDIR}/trafficserver/body_factory/default/connect\#all_down
CONF_FILES+=	${PREFIX}/share/examples/trafficserver/body_factory/default/connect\#dns_failed \
		${PKG_SYSCONFDIR}/trafficserver/body_factory/default/connect\#dns_failed
CONF_FILES+=	${PREFIX}/share/examples/trafficserver/body_factory/default/connect\#failed_connect \
		${PKG_SYSCONFDIR}/trafficserver/body_factory/default/connect\#failed_connect
CONF_FILES+=	${PREFIX}/share/examples/trafficserver/body_factory/default/connect\#hangup \
		${PKG_SYSCONFDIR}/trafficserver/body_factory/default/connect\#hangup
CONF_FILES+=	${PREFIX}/share/examples/trafficserver/body_factory/default/default \
		${PKG_SYSCONFDIR}/trafficserver/body_factory/default/default
CONF_FILES+=	${PREFIX}/share/examples/trafficserver/body_factory/default/interception\#no_host \
		${PKG_SYSCONFDIR}/trafficserver/body_factory/default/interception\#no_host
CONF_FILES+=	${PREFIX}/share/examples/trafficserver/body_factory/default/redirect\#moved_permanently \
		${PKG_SYSCONFDIR}/trafficserver/body_factory/default/redirect\#moved_permanently
CONF_FILES+=	${PREFIX}/share/examples/trafficserver/body_factory/default/redirect\#moved_temporarily \
		${PKG_SYSCONFDIR}/trafficserver/body_factory/default/redirect\#moved_temporarily
CONF_FILES+=	${PREFIX}/share/examples/trafficserver/body_factory/default/request\#cycle_detected \
		${PKG_SYSCONFDIR}/trafficserver/body_factory/default/request\#cycle_detected
CONF_FILES+=	${PREFIX}/share/examples/trafficserver/body_factory/default/request\#invalid_content_length \
		${PKG_SYSCONFDIR}/trafficserver/body_factory/default/request\#invalid_content_length
CONF_FILES+=	${PREFIX}/share/examples/trafficserver/body_factory/default/request\#no_content_length \
		${PKG_SYSCONFDIR}/trafficserver/body_factory/default/request\#no_content_length
CONF_FILES+=	${PREFIX}/share/examples/trafficserver/body_factory/default/request\#no_host \
		${PKG_SYSCONFDIR}/trafficserver/body_factory/default/request\#no_host
CONF_FILES+=	${PREFIX}/share/examples/trafficserver/body_factory/default/request\#scheme_unsupported \
		${PKG_SYSCONFDIR}/trafficserver/body_factory/default/request\#scheme_unsupported
CONF_FILES+=	${PREFIX}/share/examples/trafficserver/body_factory/default/request\#syntax_error \
		${PKG_SYSCONFDIR}/trafficserver/body_factory/default/request\#syntax_error
CONF_FILES+=	${PREFIX}/share/examples/trafficserver/body_factory/default/request\#uri_len_too_long \
		${PKG_SYSCONFDIR}/trafficserver/body_factory/default/request\#uri_len_too_long
CONF_FILES+=	${PREFIX}/share/examples/trafficserver/body_factory/default/response\#bad_response \
		${PKG_SYSCONFDIR}/trafficserver/body_factory/default/response\#bad_response
CONF_FILES+=	${PREFIX}/share/examples/trafficserver/body_factory/default/response\#bad_version \
		${PKG_SYSCONFDIR}/trafficserver/body_factory/default/response\#bad_version
CONF_FILES+=	${PREFIX}/share/examples/trafficserver/body_factory/default/timeout\#activity \
		${PKG_SYSCONFDIR}/trafficserver/body_factory/default/timeout\#activity
CONF_FILES+=	${PREFIX}/share/examples/trafficserver/body_factory/default/timeout\#inactivity \
		${PKG_SYSCONFDIR}/trafficserver/body_factory/default/timeout\#inactivity
CONF_FILES+=	${PREFIX}/share/examples/trafficserver/body_factory/default/transcoding\#unsupported \
		${PKG_SYSCONFDIR}/trafficserver/body_factory/default/transcoding\#unsupported
CONF_FILES+=	${PREFIX}/share/examples/trafficserver/body_factory/default/urlrouting\#no_mapping \
		${PKG_SYSCONFDIR}/trafficserver/body_factory/default/urlrouting\#no_mapping
CONF_FILES+=	${PREFIX}/share/examples/trafficserver/cache.config \
		${PKG_SYSCONFDIR}/trafficserver/cache.config
CONF_FILES+=	${PREFIX}/share/examples/trafficserver/hosting.config \
		${PKG_SYSCONFDIR}/trafficserver/hosting.config
CONF_FILES+=	${PREFIX}/share/examples/trafficserver/ip_allow.yaml \
		${PKG_SYSCONFDIR}/trafficserver/ip_allow.yaml
CONF_FILES+=	${PREFIX}/share/examples/trafficserver/jsonrpc.yaml \
		${PKG_SYSCONFDIR}/trafficserver/jsonrpc.yaml
CONF_FILES+=	${PREFIX}/share/examples/trafficserver/logging.yaml \
		${PKG_SYSCONFDIR}/trafficserver/logging.yaml
CONF_FILES+=	${PREFIX}/share/examples/trafficserver/parent.config \
		${PKG_SYSCONFDIR}/trafficserver/parent.config
CONF_FILES+=	${PREFIX}/share/examples/trafficserver/plugin.config \
		${PKG_SYSCONFDIR}/trafficserver/plugin.config
CONF_FILES+=	${PREFIX}/share/examples/trafficserver/records.yaml \
		${PKG_SYSCONFDIR}/trafficserver/records.yaml
CONF_FILES+=	${PREFIX}/share/examples/trafficserver/remap.config \
		${PKG_SYSCONFDIR}/trafficserver/remap.config
CONF_FILES+=	${PREFIX}/share/examples/trafficserver/sni.yaml \
		${PKG_SYSCONFDIR}/trafficserver/sni.yaml
CONF_FILES+=	${PREFIX}/share/examples/trafficserver/socks.config \
		${PKG_SYSCONFDIR}/trafficserver/socks.config
CONF_FILES+=	${PREFIX}/share/examples/trafficserver/splitdns.config \
		${PKG_SYSCONFDIR}/trafficserver/splitdns.config
CONF_FILES+=	${PREFIX}/share/examples/trafficserver/ssl_multicert.config \
		${PKG_SYSCONFDIR}/trafficserver/ssl_multicert.config
CONF_FILES+=	${PREFIX}/share/examples/trafficserver/storage.config \
		${PKG_SYSCONFDIR}/trafficserver/storage.config
CONF_FILES+=	${PREFIX}/share/examples/trafficserver/strategies.yaml \
		${PKG_SYSCONFDIR}/trafficserver/strategies.yaml
CONF_FILES+=	${PREFIX}/share/examples/trafficserver/volume.config \
		${PKG_SYSCONFDIR}/trafficserver/volume.config

post-install:
	${RM} -rf ${DESTDIR}/${PREFIX}/share/examples/trafficserver
	${MV} ${DESTDIR}/${PREFIX}/etc/trafficserver ${DESTDIR}/${PREFIX}/share/examples

.include "../../archivers/lzmalib/buildlink3.mk"
.include "../../archivers/brotli/buildlink3.mk"
.include "../../archivers/xz/buildlink3.mk"
.include "../../devel/pcre2/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../lang/LuaJIT2/buildlink3.mk"
.include "../../devel/jemalloc/buildlink3.mk"
.include "../../textproc/yaml-cpp/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
