# $NetBSD: Makefile,v 1.3 2003/11/27 17:19:05 mpasternak Exp $

DISTNAME=	# empty
PKGNAME=	PPower4-0.9.4
CATEGORIES=	print
MASTER_SITES=	http://www-sp.iti.informatik.tu-darmstadt.de/software/ppower4/
DISTFILES=	pp4sty.zip pp4p.jar

MAINTAINER=	benedikt.meurer@unix-ag.uni-siegen.de
HOMEPAGE=	http://www-sp.iti.informatik.tu-darmstadt.de/software/ppower4/
COMMENT=	PDF presentation post processor

BUILD_DEPENDS+=	unzip-[0-9]*:../../archivers/unzip
DEPENDS+=	{teTeX-bin>=1.0.6,teTeX2-bin-[0-9]*}:../../print/teTeX-bin

# This requires Java 1.2 or better
USE_JAVA=	run
USE_JAVA2=	YES

NO_CONFIGURE=	YES
NO_BUILD=	YES

EVAL_PREFIX+=	UNZIP_PREFIX=unzip
EVAL_PREFIX+=	MKTEXLSR_PREFIX=mktexlsr
UNZIP_PREFIX_DEFAULT=${LOCALBASE}
MKTEXLSR_PREFIX_DEFAULT=${LOCALBASE}

EXTRACT_CMD_OPTS.zip=	# empty
EXTRACT_ONLY=	pp4sty.zip

JARDIR=		${PREFIX}/share/texmf/java/ppower4
STYDIR=		${PREFIX}/share/texmf/tex/latex/ppower4

do-install:
	${INSTALL_DATA_DIR} ${JARDIR}
	${INSTALL_DATA_DIR} ${STYDIR}
	cd ${WRKSRC} && for f in *.sty; do \
		${INSTALL_DATA} $$f ${STYDIR}/$$f; \
	done
	${INSTALL_DATA} ${DISTDIR}/pp4p.jar ${JARDIR}/pp4p.jar
	${INSTALL_SCRIPT} ${FILESDIR}/ppower4.sh ${PREFIX}/bin/ppower4

post-install:
	@${MKTEXLSR_PREFIX}/bin/mktexlsr

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
