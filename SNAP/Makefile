# $NetBSD$

GITHUB_PROJECT=	SNAP
GITHUB_TAG=	b90c63a6a8af711323249c542d0587f20722712e
DISTNAME=	master
PKGNAME=	${GITHUB_PROJECT}-0.0.0.20210910
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_GITHUB:=KorfLab/}
DIST_SUBDIR=	${GITHUB_PROJECT}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/KorfLab/SNAP/
COMMENT=	Gene finding for prokaryotic and eukaryotic genomes
LICENSE=	mit

WRKSRC=		${WRKDIR}/SNAP-${GITHUB_TAG}
USE_LANGUAGES+=	c
USE_TOOLS+=	gmake pax
BUILD_TARGET+=	default

INSTALLATION_DIRS+=	bin share/SNAP/Zoe
PROGRAMS=		fathom forge snap Zoe/zoe-loop
HMMS=			README.md brugia ciona fly mosquito rice thale worm *.hmm

do-install:
.for f in ${PROGRAMS}
	${INSTALL_PROGRAM} ${WRKSRC}/${f} ${DESTDIR}${PREFIX}/bin
.endfor
	cd ${WRKSRC}/HMM && ${PAX} -rw ${HMMS} ${DESTDIR}${PREFIX}/share/SNAP/Zoe
	${CHMOD} a-w ${DESTDIR}${PREFIX}/share/SNAP/Zoe/*

.include "../../mk/bsd.pkg.mk"
