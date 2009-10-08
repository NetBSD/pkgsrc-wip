# $NetBSD: Makefile,v 1.10 2009/10/08 23:02:58 thomasklausner Exp $

DISTNAME=	# empty
PKGNAME=	PPower4-0.9.4
CATEGORIES=	print
MASTER_SITES=	http://www-sp.iti.informatik.tu-darmstadt.de/software/ppower4/
DISTFILES=	pp4sty.zip pp4p.jar

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www-sp.iti.informatik.tu-darmstadt.de/software/ppower4/
COMMENT=	PDF presentation post processor

PKG_DESTDIR_SUPPORT=	user-destdir

# This requires Java 1.2 or better
USE_JAVA=	run
USE_JAVA2=	yes

NO_CONFIGURE=	YES

EVAL_PREFIX+=	MKTEXLSR_PREFIX=mktexlsr
MKTEXLSR_PREFIX_DEFAULT=${LOCALBASE}

EXTRACT_ONLY=	pp4sty.zip

JARDIR=		${PREFIX}/share/texmf/java/ppower4
STYDIR=		${PREFIX}/share/texmf/tex/latex/ppower4

INSTALLATION_DIRS+=	bin ${JARDIR} ${STYDIR}

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

post-install:
	@${MKTEXLSR_PREFIX}/bin/mktexlsr

.include "../../mk/java-vm.mk"
.include "../../mk/tex.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
