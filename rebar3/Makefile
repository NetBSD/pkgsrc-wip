# $NetBSD: Makefile,v 1.3 2019/11/03 10:39:29 rillig Exp $

DISTNAME=	rebar3-3.13.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=erlang/}
DIST_SUBDIR=	rebar3

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/erlang/rebar3/
COMMENT=	Erlang build tool
LICENSE=	apache-2.0

USE_TOOLS+=	tar

REBAR_DEPS+=	bbmustache-1.8.0
REBAR_DEPS+=	certifi-2.5.1
REBAR_DEPS+=	cf-0.2.2
REBAR_DEPS+=	cth_readable-1.4.6
REBAR_DEPS+=	erlware_commons-1.3.1
REBAR_DEPS+=	eunit_formatters-0.5.0
REBAR_DEPS+=	getopt-1.0.1
REBAR_DEPS+=	parse_trans-3.3.0
REBAR_DEPS+=	providers-1.8.1
REBAR_DEPS+=	relx-3.33.0
REBAR_DEPS+=	ssl_verify_fun-1.1.5

MAKE_ENV+=	DEBUG=1

DISTFILES=	${DEFAULT_DISTFILES}

.for dep in ${REBAR_DEPS}
DISTFILES+=		${dep}.tar
SITES.${dep}.tar=	https://repo.hex.pm/tarballs/
EXTRACT_DIR.${dep}.tar=	${WRKSRC}/_build/default/lib/${dep:C/-.*//}
.endfor

#DISTFILES+=				${DISTNAME:S/-/-cache-/}.tar.gz
#SITES.${DISTNAME:S/-/-cache-/}.tar.gz=	https://ftp.netbsd.org/pub/NetBSD/misc/fhajny/

SUBST_CLASSES+=		escript
SUBST_STAGE.escript=	pre-configure
SUBST_MESSAGE.escript=	Fix default escript shebang
SUBST_FILES.escript=	src/rebar_prv_escriptize.erl
SUBST_SED.escript=	-e 's,/usr/bin/env escript,${PREFIX}/bin/escript,'

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1 share/examples/rebar3

# convenience target to rebuild the rebar3 cache file
build-cache:
	cd ${WRKDIR} && ${TAR} -c -v -z -f rebar3-cache-${PKGVERSION}${EXTRACT_SUFX} .home

# post-extract:
# .for dep in ${REBAR_DEPS}
# 	${MKDIR} ${WRKSRC}/_build/default/lib/${dep:C/-.*//}
# 	${TAR} xOf ${DISTDIR}/rebar3/${dep}.tar contents.tar.gz |\
# 		${TAR} xfz - -C ${WRKSRC}/_build/default/lib/${dep:C/-.*//}
# .endfor
# 	${MKDIR} ${WRKSRC}/_build/bootstrap/lib
# 	${MKDIR} ${WRKSRC}/_build/bootstrap/plugins
# .for dep in ${REBAR_DEPS}
# 	${LN} -sf ${WRKSRC}/_build/default/lib/${dep:C/-.*//} ${WRKSRC}/_build/bootstrap/lib/
# .endfor

post-extract:
	${MKDIR} -p ${WRKSRC}/_build/bootstrap/lib
.for dep in ${REBAR_DEPS}
	cd ${WRKSRC}/_build/default/lib/${dep:C/-.*//} && \
		${TAR} -xzf contents.tar.gz
	${LN} -sf ../../default/lib/${dep:C/-.*//} \
		${WRKSRC}/_build/bootstrap/lib/${dep:C/-.*//}
.endfor

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ./bootstrap

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/rebar3 ${DESTDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/manpages/rebar3.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/
	${INSTALL_DATA} ${WRKSRC}/rebar.config.sample \
		${DESTDIR}${PREFIX}/share/examples/rebar3

.include "../../lang/erlang/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
