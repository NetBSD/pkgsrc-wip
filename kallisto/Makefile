# $NetBSD: Makefile,v 1.1 2018/12/21 19:00:56 bacon Exp $

DISTNAME=	kallisto-0.46.1
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_GITHUB:=pachterlab/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	https://pachterlab.github.io/kallisto/
COMMENT=	Quantify abundances of transcripts from RNA-Seq data
LICENSE=	2-clause-bsd

USE_LANGUAGES=	c c++
USE_TOOLS+=	autoconf autoreconf automake gmake pax
USE_CMAKE=	yes

SUBST_CLASSES+=		test
SUBST_STAGE.test=	post-build
SUBST_FILES.test=	kallisto-test
SUBST_SED.test=		-e 's|/usr/local/share/kallisto|${DATADIR}|g'

DATADIR=	${PREFIX}/share/kallisto

INSTALLATION_DIRS=	bin ${DATADIR}
MAKE_JOBS_SAFE=		no

post-extract:
	${CP} ${FILESDIR}/kallisto-test ${WRKSRC}

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/kallisto-test ${DESTDIR}${PREFIX}/bin
	cd ${WRKSRC} && pax -rw test ${DESTDIR}${DATADIR}

# .include "../../biology/htslib/buildlink3.mk"
.include "../../devel/hdf5/buildlink3.mk"
.include "../../wip/libaec/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
