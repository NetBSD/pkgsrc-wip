# $NetBSD$

GITHUB_PROJECT=	xmatchview
GITHUB_TAG=	refs/tags/v1.2.5
DISTNAME=	v1.2.5
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME:S,^v,,}
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_GITHUB:=bcgsc/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/bcgsc/xmatchview/
COMMENT=	Genome alignment visualization
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}/xmatchview-1.2.5
USE_LANGUAGES=	# none
USE_TOOLS+=	pax
NO_BUILD=	yes

DEPENDS+=	${PYPKGPREFIX}-Pillow>=8.2.0:../../graphics/py-Pillow

REPLACE_PYTHON+=	xmatchview-conifer.py
REPLACE_PYTHON+=	xmatchview-hive.py
REPLACE_PYTHON+=	xmatchview.py

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	pre-configure
SUBST_FILES.prefix=	test/Makefile
SUBST_VARS.prefix=	PREFIX

TEST_TARGET=	all
TEST_DIRS=	test test-hive
TEST_ENV+=	XMATCHVIEW=../xmatchview.py
TEST_ENV+=	XMATCHVIEW_HIVE=../xmatchview-hive.py
TEST_ENV+=	XMATCHVIEW_FONTDIR=../tarballs/fonts

post-extract:
	${CP} ${FILESDIR}/Makefile.xmatchview ${WRKSRC}/test/Makefile
	${CP} ${FILESDIR}/Makefile.xmatchview-hive ${WRKSRC}/test-hive/Makefile

INSTALLATION_DIRS+=	bin share/doc/xmatchview share/fonts/xmatchview
INSTALLATION_DIRS+=	share/examples/xmatchview/xmatchview
INSTALLATION_DIRS+=	share/examples/xmatchview/xmatchview-hive

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/xmatchview-conifer.py ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/xmatchview-hive.py ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/xmatchview.py ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README.md ${DESTDIR}${PREFIX}/share/doc/xmatchview
	${INSTALL_DATA} ${WRKSRC}/paper/paper.md ${DESTDIR}${PREFIX}/share/doc/xmatchview
	${INSTALL_DATA} ${WRKSRC}/paper/paper.pdf ${DESTDIR}${PREFIX}/share/doc/xmatchview
	cd ${WRKSRC}/tarballs/fonts && ${PAX} -rw * ${DESTDIR}${PREFIX}/share/fonts/xmatchview 
	${INSTALL_SCRIPT} ${WRKSRC}/runCompareTwoGenomesColinear.sh ${DESTDIR}${PREFIX}/share/examples/xmatchview
	${INSTALL_SCRIPT} ${WRKSRC}/runSpruceView.sh ${DESTDIR}${PREFIX}/share/examples/xmatchview
	cd ${WRKSRC}/test \
	&& ${RM} -f xmv-FTL1_pa.fa_vs_FTL1_ss.fa.rep_m10_b10_r1_c2.png \
	&& ${RM} -f xmv-FTL1_paMF.fa_vs_FTL1_ssMF.fa.paf_m80_b10_r1_c2.png \
	&& ${PAX} -rw * ${DESTDIR}${PREFIX}/share/examples/xmatchview/xmatchview
	cd ${WRKSRC}/test-hive \
	&& ${RM} -f xmv-hive_i0_b1_c30_a0.75.svg \
	&& ${PAX} -rw * ${DESTDIR}${PREFIX}/share/examples/xmatchview/xmatchview-hive

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
