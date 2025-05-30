# $NetBSD: Makefile,v 1.1 2018/12/21 19:00:56 bacon Exp $

DISTNAME=	kallisto-0.51.1
PKGREVISION=	1
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_GITHUB:=pachterlab/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

OWNER=		bacon@NetBSD.org
HOMEPAGE=	https://pachterlab.github.io/kallisto/
COMMENT=	Quantify abundances of transcripts from RNA-Seq data
LICENSE=	2-clause-bsd

USE_TOOLS+=	autoconf gmake pax
USE_LANGUAGES=	c c++

SUBST_CLASSES+=		test
SUBST_STAGE.test=	pre-configure
SUBST_FILES.test=	kallisto-test
SUBST_SED.test=		-e 's|/usr/local/share/kallisto|${DATADIR}|g'

CMAKE_CONFIGURE_ARGS+=	-DUSE_HDF5:BOOL=ON -DCMAKE_VERBOSE_MAKEFILE:BOOL=ON
# Build fails on 8-core Mac M1
MAKE_JOBS_SAFE=		no
INSTALLATION_DIRS+=	${DATADIR}

DATADIR=		${PREFIX}/share/kallisto

post-extract:
	${CP} ${FILESDIR}/kallisto-test ${WRKSRC}
	${RM} -rf ${WRKSRC}/ext/htslib

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/kallisto-test ${DESTDIR}${PREFIX}/bin
	cd ${WRKSRC} && pax -rw test ${DESTDIR}${DATADIR}

.include "../../devel/cmake/build.mk"
.include "../../devel/hdf5/buildlink3.mk"
.include "../../archivers/libaec/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../biology/htslib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
