# $NetBSD: Makefile,v 1.3 2014/10/09 06:42:33 fhajny Exp $

DISTNAME=	ncbi-blast-${PKGVERSION_NOREV}+-src
PKGNAME=	blast-2.2.30
CATEGORIES=	biology
MASTER_SITES=	ftp://ftp.ncbi.nlm.nih.gov/blast/executables/blast+/${PKGVERSION_NOREV}/

MAINTAINER=	jwbacon@tds.net
HOMEPAGE=	http://blast.ncbi.nlm.nih.gov/
COMMENT=	NCBI Basic Local Alignment Search Tool (Blast)
LICENSE=	public-domain

USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake perl:run

GNU_CONFIGURE=	yes

WRKSRC=		${WRKDIR}/${DISTNAME}/c++

REPLACE_PERL=	src/app/blast/legacy_blast.pl \
 		src/app/blast/update_blastdb.pl
REPLACE_PYTHON=	src/app/winmasker/windowmasker_2.2.22_adapter.py

CHECK_PORTABILITY_SKIP=	compilers/xcode30_prj/configure \
			scripts/common/check/check_make_cfg.sh \
			src/app/oligofar/tests/set1/test-oligofar.sh

# The configure script forces symbol stripping
CONFIGURE_SCRIPT=	./configure.orig

CONFIGURE_ARGS+=	AR="ar cr" \
			--prefix=${PREFIX} --with-build-root=${WRKSRC}/Release \
			--with-dll --with-mt --without-caution --without-debug

# amq -w hangs on BSD, not needed
CONFIGURE_ENV+=		ncbi_cv_prog_amq_w=no

# Default behavior patched so that all 3rd party support disable
# by default, then enabled one by one
CONFIGURE_ARGS+=	--without-3psw \
			--with-bz2=yes --with-pcre=yes --with-z=yes

# Needed for FreeBSD port on FreeBSD 10.0
# post-patch:
# 	${REINPLACE_CMD} \
# 		-e "s|-D_THREAD_SAFE|-D_THREAD_SAFE -D__RUNETYPE_INTERNAL|g" \
# 		${WRKSRC}/src/build-system/configure

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
