# $NetBSD$

DISTNAME=	zeek-4.0.0
CATEGORIES=	net security
MASTER_SITES=	${MASTER_SITE_GITHUB:=zeek/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://zeek.org/
COMMENT=	Passive network traffic analyzer
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3

GCC_REQD+=	7
USE_LANGUAGES=	c c++17
USE_TOOLS+=	bash:run bison cmake flex pkg-config

BUILD_DEFS+=		VARBASE
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--mandir=${PREFIX}/${PKGMANDIR}
CONFIGURE_ARGS+=	--logdir=${VARBASE}/log/${PKGBASE}
CONFIGURE_ARGS+=	--spooldir=${VARBASE}/spool/${PKGBASE}
CONFIGURE_ARGS+=	--conf-files-dir=${PKG_SYSCONFDIR}
HAS_CONFIGURE=		yes
PKG_SYSCONFSUBDIR=	${PKGBASE}

PKGCONFIG_OVERRIDE+=	auxil/libkqueue/libkqueue.pc.in
PKGCONFIG_OVERRIDE+=	auxil/rapidjson/RapidJSON.pc.in
PKGCONFIG_OVERRIDE+=	auxil/rapidjson/thirdparty/gtest/googlemock/cmake/gmock.pc.in
PKGCONFIG_OVERRIDE+=	auxil/rapidjson/thirdparty/gtest/googlemock/cmake/gmock_main.pc.in
PKGCONFIG_OVERRIDE+=	auxil/rapidjson/thirdparty/gtest/googletest/cmake/gtest.pc.in
PKGCONFIG_OVERRIDE+=	auxil/rapidjson/thirdparty/gtest/googletest/cmake/gtest_main.pc.in

EGDIR=		${PREFIX}/share/examples/${PKGBASE}
CONF_FILES=	${EGDIR}/networks.cfg ${PKG_SYSCONFDIR}/networks.cfg
CONF_FILES+=	${EGDIR}/node.cfg ${PKG_SYSCONFDIR}/node.cfg
CONF_FILES+=	${EGDIR}/zeekctl.cfg ${PKG_SYSCONFDIR}/zeekctl.cfg
CONF_FILES+=	${EGDIR}/zkg/config ${PKG_SYSCONFDIR}/zkg/config
OWN_DIRS+=	${PKG_SYSCONFDIR}/zkg

SUBST_CLASSES+=		cfg
SUBST_FILES.cfg+=	CMakeLists.txt
SUBST_FILES.cfg+=	auxil/zeekctl/CMakeLists.txt
SUBST_SED.cfg+=		-e "s,@EGDIR@,${PREFIX}/share/examples/${PKGBASE},g"
SUBST_STAGE.cfg=	pre-configure

REPLACE_BASH=		auxil/btest/btest-ask-update
REPLACE_BASH+=		auxil/btest/btest-bg-run
REPLACE_BASH+=		auxil/btest/btest-bg-run-helper
REPLACE_BASH+=		auxil/btest/btest-bg-wait
REPLACE_BASH+=		auxil/btest/btest-diff
REPLACE_BASH+=		auxil/btest/btest-progress
REPLACE_BASH+=		auxil/btest/sphinx/btest-diff-rst
REPLACE_BASH+=		auxil/btest/sphinx/btest-rst-cmd
REPLACE_BASH+=		auxil/btest/sphinx/btest-rst-include
REPLACE_BASH+=		auxil/btest/sphinx/btest-rst-pipe
REPLACE_BASH+=		auxil/zeekctl/bin/archive-log
REPLACE_BASH+=		auxil/zeekctl/bin/check-config
REPLACE_BASH+=		auxil/zeekctl/bin/crash-diag
REPLACE_BASH+=		auxil/zeekctl/bin/delete-log
REPLACE_BASH+=		auxil/zeekctl/bin/expire-crash
REPLACE_BASH+=		auxil/zeekctl/bin/expire-logs
REPLACE_BASH+=		auxil/zeekctl/bin/helpers/check-pid
REPLACE_BASH+=		auxil/zeekctl/bin/helpers/df
REPLACE_BASH+=		auxil/zeekctl/bin/helpers/first-line
REPLACE_BASH+=		auxil/zeekctl/bin/helpers/start
REPLACE_BASH+=		auxil/zeekctl/bin/helpers/stop
REPLACE_BASH+=		auxil/zeekctl/bin/helpers/top
REPLACE_BASH+=		auxil/zeekctl/bin/make-archive-name
REPLACE_BASH+=		auxil/zeekctl/bin/post-terminate
REPLACE_BASH+=		auxil/zeekctl/bin/postprocessors/summarize-connections
REPLACE_BASH+=		auxil/zeekctl/bin/run-zeek
REPLACE_BASH+=		auxil/zeekctl/bin/run-zeek-on-trace
REPLACE_BASH+=		auxil/zeekctl/bin/send-mail
REPLACE_BASH+=		zeek-wrapper.in
REPLACE_PYTHON=		auxil/btest/btest
REPLACE_PYTHON+=	auxil/btest/btest-setsid
REPLACE_PYTHON+=	auxil/package-manager/zkg
REPLACE_PYTHON+=	auxil/zeekctl/bin/stats-to-csv
REPLACE_PYTHON+=	auxil/zeekctl/bin/zeekctl.in

INSTALLATION_DIRS+=	${EGDIR}

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"

DARWIN_BINS=	bin/broker-benchmark bin/broker-cluster-benchmark bin/zeek
DARWIN_BINS+=	lib/zeek/python/broker/_broker.so

.PHONY: fix-darwin-install-name
post-install: fix-darwin-install-name
fix-darwin-install-name:
.  for bin in ${DARWIN_BINS}
	otool -XL ${DESTDIR}${PREFIX}/${bin}				\
	  | ${GREP} '@rpath' | while read rpath rest; do		\
	    install_name_tool -change $$rpath				\
	      `${ECHO} $$rpath | ${SED} -e 's,@rpath,${PREFIX}/lib,g'`	\
	      ${DESTDIR}${PREFIX}/${bin};				\
	done
.  endfor
	for f in ${DESTDIR}${PREFIX}/lib/lib*.dylib; do			\
	  install_name_tool -id						\
	    `${ECHO} $$f | ${SED} -e 's,${DESTDIR},,g'` $$f;		\
	  otool -XL $$f | ${GREP} '@rpath' | while read rpath rest; do	\
	    install_name_tool -change $$rpath				\
	      `${ECHO} $$rpath | ${SED} -e 's,@rpath,${PREFIX}/lib,g'`	\
	      $$f;							\
	  done;								\
	done
.endif

.include "../../devel/swig3/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
