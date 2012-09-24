# $NetBSD: Makefile,v 1.13 2012/09/24 16:56:27 asau Exp $

DISTNAME=	# empty
PKGNAME=	PPower4-0.9.4
CATEGORIES=	print
MASTER_SITES=	http://www-sp.iti.informatik.tu-darmstadt.de/software/ppower4/
DISTFILES=	pp4sty.zip pp4p.jar

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www-sp.iti.informatik.tu-darmstadt.de/software/ppower4/
COMMENT=	PDF presentation post processor
LICENSE=	gnu-gpl-v3

DEPENDS+=	tex-eso-pic-[0-9]*:../../print/tex-eso-pic
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-hyperref-[0-9]*:../../print/tex-hyperref

# This requires Java 1.2 or better
USE_JAVA=	run
USE_JAVA2=	yes

NO_CONFIGURE=	YES

EXTRACT_ONLY=	pp4sty.zip

JARDIR=		${PREFIX}/share/texmf/java/ppower4
STYDIR=		${PREFIX}/share/texmf/tex/latex/ppower4

INSTALLATION_DIRS+=	bin ${JARDIR} ${STYDIR}

TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf

do-build:
	${SED}  -e "s,@RCD_SCRIPTS_SHELL@,${RCD_SCRIPTS_SHELL},g" \
		-e "s,java -jar ..jarfile.,${JAVA_BINPREFIX}-java -jar ${JARDIR}/pp4p.jar," \
		< ${FILESDIR}/ppower4.sh > ${WRKSRC}/ppower4
do-install:
	cd ${WRKSRC} && for f in *.sty; do \
		${INSTALL_DATA} $$f ${DESTDIR}${STYDIR}/$$f; \
	done
	${INSTALL_DATA} ${DISTDIR}/pp4p.jar ${DESTDIR}${JARDIR}/pp4p.jar
	${INSTALL_SCRIPT} ${WRKSRC}/ppower4 ${DESTDIR}${PREFIX}/bin

.include "../../mk/java-vm.mk"
.include "../../print/kpathsea/texmf.mk"
.include "../../mk/bsd.pkg.mk"
