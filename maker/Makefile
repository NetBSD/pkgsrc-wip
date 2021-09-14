# $NetBSD$

DISTNAME=	maker-3.01.04
CATEGORIES=	biology
MASTER_SITES=	http://weatherby.genetics.utah.edu/maker_downloads/E446/83FE/1E2C/EFF4EA9B639AD79928609B719046/ # XXX - private link
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.yandell-lab.org/software/maker.html
COMMENT=	Genome annotation pipeline
LICENSE=	artistic OR gnu-gpl-v3

WRKSRC=		${WRKDIR}/maker
USE_TOOLS+=	pax perl
USE_LANGUAGES=	# none

DEPENDS+=	bioperl>=1.7.7:../../biology/bioperl
DEPENDS+=	p5-DBD-SQLite>=1.66:../../databases/p5-DBD-SQLite
DEPENDS+=	p5-DBD-postgresql>=3.14.2:../../databases/p5-DBD-postgresql # option?
DEPENDS+=	p5-Bit-Vector>=7.4:../../devel/p5-Bit-Vector
DEPENDS+=	p5-IO-All>=0.87:../../devel/p5-IO-All
DEPENDS+=	p5-Inline-C>=0.81:../../devel/p5-Inline-C
DEPENDS+=	p5-Want>=0.29:../../devel/p5-Want
DEPENDS+=	p5-forks>=0.36:../../devel/p5-forks

DEPENDS+=	p5-Perl-Unsafe-Signals>=0.03:../../wip/p5-Perl-Unsafe-Signals # devel
DEPENDS+=	exonerate>=2.2.0:../../wip/exonerate
DEPENDS+=	repeatmasker>=4.1.2.1:../../wip/repeatmasker
DEPENDS+=	SNAP>=0.0.0.20190603:../../wip/SNAP

REPLACE_PERL+=	lib/Datastore/bin/ds_dir
REPLACE_PERL+=	lib/Datastore/bin/ds_do
REPLACE_PERL+=	lib/File/maintain.pl
REPLACE_PERL+=	lib/Gene_obj.pm
REPLACE_PERL+=	lib/Longest_orf.pm
REPLACE_PERL+=	lib/Nuc_translator.pm
REPLACE_PERL+=	lib/Widget/fgenesh/fgenesh_wrap
REPLACE_PERL+=	lib/Widget/genemark/gmhmm_wrap

SUBST_CLASSES+=		PATH
SUBST_STAGE.PATH=	post-build
SUBST_FILES.PATH=	perl/lib/MAKER/ConfigData.pm
SUBST_SED.PATH+=	-e 's,${WRKDIR}/.cwrapper/bin:,,'
SUBST_SED.PATH+=	-e 's,${WRKDIR}/.buildlink/bin:,,'
SUBST_SED.PATH+=	-e 's,${WRKDIR}/.tools/bin:,,'
SUBST_SED.PATH+=	-e 's,${WRKSRC}/src/../,${PREFIX}/maker,'

INSTALLATION_DIRS+=	maker share/doc/maker

post-extract:
	${CHMOD} a-x ${WRKSRC}/lib/CGL/Annotation/GFF3/DictyBase.pm
	${CHMOD} a-x ${WRKSRC}/lib/CGL/Annotation/GFF3/FlyBase.pm
	${CHMOD} a-x ${WRKSRC}/lib/CGL/Annotation/GFF3/Maker.pm
	${CHMOD} a-x ${WRKSRC}/lib/CGL/Annotation/GFF3/WormBase.pm
	${CHMOD} a-x ${WRKSRC}/lib/CGL/Annotation/GFF3/nGASP.pm
	${CHMOD} a-x ${WRKSRC}/lib/CGL/Annotation/GFF3/nGASP2.pm
	${CHMOD} a-x ${WRKSRC}/lib/Dumper/XML/Game_Xml.pm
	${CHMOD} a-x ${WRKSRC}/lib/evaluator/gff3_to_phatHit/FlyBase.pm
	${CHMOD} a-x ${WRKSRC}/lib/evaluator/gff3_to_phatHit/Maker.pm
	${CHMOD} a-x ${WRKSRC}/lib/evaluator/gff3_to_phatHit/WormBase.pm
	${CHMOD} a-x ${WRKSRC}/lib/polisher/exonerate/altest.pm
	${CHMOD} a-x ${WRKSRC}/lib/polisher/exonerate/est.pm
	${CHMOD} a-x ${WRKSRC}/lib/polisher/exonerate/protein.pm

do-configure:
	cd ${WRKSRC}/src && ${PERL5} Build.PL

do-build:
	cd ${WRKSRC}/src && ${PERL5} Build install

do-install:
	cd ${WRKSRC} && ${PAX} -rw bin data lib perl ${DESTDIR}${PREFIX}/maker
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/maker

.include "../../mk/bsd.pkg.mk"
