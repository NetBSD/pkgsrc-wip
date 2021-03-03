# $NetBSD$

GITHUB_PROJECT=	tg
GITHUB_TAG=	20200106
DISTNAME=	20200106
PKGNAME=	telegram-cli-${DISTNAME}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=kenorb-contrib/}
DIST_SUBDIR=	${GITHUB_PROJECT}

TOOL_DEPENDS+= git-[0-9]*:../../devel/git

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/kenorb-contrib/tg/
COMMENT=	CLI for telegram messenger
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE= yes
USE_TOOLS+= gmake
CONFIGURE_ARGS+= --disable-python
CONFIGURE_ARGS+= --disable-liblua

SUBST_CLASSES+= fix-paths
SUBST_STAGE.fix-paths= pre-configure
SUBST_FILES.fix-paths= ${WRKSRC}/Makefile.in
SUBST_SED.fix-paths= -e 's,/usr/local,${DESTDIR}/${PREFIX},g'

post-patch:
	${RUN}cd ${WRKDIR}/tg-${GITHUB_TAG} && git clone https://github.com/kenorb-contrib/tgl tgl

.include "../../devel/libevent/buildlink3.mk"
.include "../../devel/libconfig/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/jansson/buildlink3.mk"
# url2pkg-marker (please do not remove this line.)
.include "../../mk/bsd.pkg.mk"
