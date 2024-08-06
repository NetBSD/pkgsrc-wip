# $NetBSD$

DISTNAME=	v0.0.1_update20200803
PKGNAME=	${GITHUB_PROJECT:tl}-${DISTNAME:S,^v,,:S,_update,.,}
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_GITHUB:=xiaochuanle/}
GITHUB_PROJECT=	NECAT
GITHUB_TAG=	refs/tags/v0.0.1_update20200803
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/xiaochuanle/NECAT/
COMMENT=	Error correction and de-novo assembler Nanopore reads
#LICENSE=	# TODO: (see mk/license.mk)

WRKSRC=			${WRKDIR}/NECAT-0.0.1_update20200803
BUILD_DIRS=		src
USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake pax perl:run
CHECK_RELRO_SUPPORTED=	no

REPLACE_PERL=	src/pipeline/necat.pl

REPLACE_SH+=	scripts/oc2asmpm.sh
REPLACE_SH+=	scripts/oc2cmd.sh
REPLACE_SH+=	scripts/oc2cns.sh
REPLACE_SH+=	scripts/oc2cns_iter.sh
REPLACE_SH+=	scripts/oc2ctgpm.sh
REPLACE_SH+=	scripts/oc2trim.sh
REPLACE_SH+=	scripts/oc2trim_bases.sh
REPLACE_SH+=	scripts/ontsa.sh

INSTALLATION_DIRS+=	bin

do-install:
	cd ${WRKSRC}/bin && ${PAX} -rw . ${DESTDIR}${PREFIX}/bin
	${CHMOD} a-x ${DESTDIR}${PREFIX}/bin/refmap.sh
	${CHMOD} a-x ${DESTDIR}${PREFIX}/bin/run_ctgpm.sh
	# ${RM} -r ${DESTDIR}${PREFIX}/bin/Plgd
	${RM} -r ${DESTDIR}${PREFIX}/bin/trim_bases_accurate
	${RM} -r ${DESTDIR}${PREFIX}/bin/trim_bases_accurate0
	${RM} ${DESTDIR}${PREFIX}/bin/test.sh

.include "../../mk/bsd.pkg.mk"
