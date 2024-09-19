# $NetBSD$

GITHUB_PROJECT=	nanostat
GITHUB_TAG=	f50c753
DISTNAME=	NanoStat-1.5.0.20210108
CATEGORIES=	biology python
MASTER_SITES=	${MASTER_SITE_GITHUB:=wdecoster/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/wdecoster/nanostat
COMMENT=	Statistics for Oxford Nanopore sequencing data and alignments
LICENSE=	gnu-gpl-v3

DEPENDS+=	nanoget>=1.12.2:../../wip/nanoget
DEPENDS+=	nanomath>=1.0.0:../../wip/nanomath
DEPENDS+=	${PYPKGPREFIX}-deprecated>=1.2.7:../../devel/py-deprecated
DEPENDS+=	${PYPKGPREFIX}-pysam>=0.15.1:../../wip/py-pysam

WRKSRC=		${WRKDIR}/nanostat-f50c7530f072e9e2b3c830334d806a619dc37c68
USE_LANGUAGES=	# none

EGG_NAME=	${DISTNAME:C/\.[[:digit:]]+$$//}

post-install:
	${RM} -r ${DESTDIR}${PREFIX}/${PYSITELIB}/scripts

.include "../../lang/python/egg.mk"
.include "../../biology/htslib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
