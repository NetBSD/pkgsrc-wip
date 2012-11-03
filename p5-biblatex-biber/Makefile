# $NetBSD: Makefile,v 1.3 2012/11/03 19:41:29 kristerw Exp $
#

DISTNAME=	biblatex-biber
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	wip
MASTER_SITES=	http://downloads.sourceforge.net/project/biblatex-biber/biblatex-biber/1.2/

MAINTAINER=	INSERT_YOUR_MAIL_ADDRESS_HERE
HOMEPAGE=	http://downloads.sourceforge.net/project/biblatex-biber/biblatex-biber/1.2/
COMMENT=	TODO: Short description of the package
#LICENSE=	# TODO: (see mk/license.mk)

# TODO: Look for the dependencies in Build.PL.

WRKSRC=			${WRKDIR}/biblatex-biber-1.2
PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/Biber/Config/.packlist
USE_LANGUAGES=		# none

DEPENDS+=		p5-Data-Compare-[0-9]*:../../devel/p5-Data-Compare
DEPENDS+=		p5-Data-Dump-[0-9]*:../../devel/p5-Data-Dump
DEPENDS+=		p5-Date-Simple-[0-9]*:../../devel/p5-Date-Simple
DEPENDS+=		p5-File-Slurp-[0-9]*:../../devel/p5-File-Slurp
DEPENDS+=		p5-File-Slurp-Unicode-[0-9]*:../../devel/p5-File-Slurp-Unicode
DEPENDS+=		p5-List-AllUtils-[0-9]*:../../devel/p5-List-AllUtils
DEPENDS+=		p5-Log-Log4perl-[0-9]*:../../devel/p5-Log-Log4perl
DEPENDS+=		p5-Regexp-Common-[0-9]*:../../textproc/p5-Regexp-Common
DEPENDS+=		p5-Unicode-Collate>=0.89:../../converters/p5-Unicode-Collate
DEPENDS+=		p5-XML-LibXML-Simple-[0-9]*:../../textproc/p5-XML-LibXML-Simple
DEPENDS+=		p5-XML-LibXSLT-[0-9]*:../../textproc/p5-XML-LibXSLT
DEPENDS+=		p5-XML-Writer-[0-9]*:../../textproc/p5-XML-Writer
DEPENDS+=		p5-XML-Writer-String-[0-9]*:../../textproc/p5-XML-Writer-String
DEPENDS+=		p5-Business-ISSN-[0-9]*:../../wip/p5-Business-ISSN
DEPENDS+=		p5-Business-ISMN-[0-9]*:../../wip/p5-Business-ISMN

DEPENDS+=		p5-Readonly-XS-[0-9]*:../../devel/p5-Readonly-XS
DEPENDS+=		tex-biblatex-[0-9]*:../../print/tex-biblatex

DEPENDS+=		p5-IPC-Run3-[0-9]*:../../devel/p5-IPC-Run3
DEPENDS+=		p5-Text-BibTeX>=0.64:../../textproc/p5-Text-BibTeX
DEPENDS+=		p5-libwww-[0-9]*:../../www/p5-libwww

BUILD_DEPENDS+=		p5-ExtUtils-LibBuilder>=0.4:../../devel/p5-ExtUtils-LibBuilder
BUILD_DEPENDS+=		p5-Config-AutoConf>=0.1:../../devel/p5-Config-AutoConf

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
