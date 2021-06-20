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
NO_BUILD=	yes

DEPENDS+=	${PYPKGPREFIX}-Pillow>=8.2.0:../../graphics/py-pillow

REPLACE_PYTHON+=	xmatchview-conifer.py
REPLACE_PYTHON+=	xmatchview-hive.py
REPLACE_PYTHON+=	xmatchview.py

INSTALLATION_DIRS+=	bin share/doc/xmatchview

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/xmatchview-conifer.py ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/xmatchview-hive.py ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/xmatchview.py ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README.md ${DESTDIR}${PREFIX}/share/doc/xmatchview
	${INSTALL_DATA} ${WRKSRC}/paper/paper.md ${DESTDIR}${PREFIX}/share/doc/xmatchview
	${INSTALL_DATA} ${WRKSRC}/paper/paper.pdf ${DESTDIR}${PREFIX}/share/doc/xmatchview

do-test:
	cd ${WRKSRC}/test \
	&& ./runXMV.sh FTL1_pa.fa_vs_FTL1_ss.fa.rep FTL1_pa.fa FTL1_ss.fa 200 10 2 FTL1_pa.gff FTL1_ss.gff
	cd ${WRKSRC}/test-hive \
	&& ../xmatchview-hive.py -q 2019-nCoV.txt -r SARS-CoV.txt -s MERS-CoV.txt -x 2019-nCoV.fa_vs_SARS-CoV.fa.rep -y 2019-nCoV.fa_vs_MERS-CoV.fa.rep -z MERS-CoV.fa_vs_SARS-CoV.fa.rep -e SARScds.gff -i 0 -b 1 -c 30 -a 0.75

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
