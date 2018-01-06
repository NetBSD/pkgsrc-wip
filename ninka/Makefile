# $NetBSD: Makefile,v 1.4 2013/03/04 21:58:38 thomasklausner Exp $
#

DISTNAME=	ninka-1.3.2pre20180106
CATEGORIES=	devel

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://ninka.turingmachine.org/
COMMENT=	License identification tool for Source Code
LICENSE=	gnu-gpl-v2

GIT_REPOSITORIES=	ninka
GIT_REPO.ninka=		https://github.com/dmgerman/ninka
GIT_REVISION.ninka=	81f185261c8863c5b84344ee31192870be939faf
PKGREVISION=		0

DEPENDS+=	p5-Getopt-Long>=2.38:../../devel/p5-Getopt-Long
DEPENDS+=	p5-DBI-[0-9]*:../../databases/p5-DBI
DEPENDS+=	p5-DBD-SQLite-[0-9]*:../../databases/p5-DBD-SQLite
DEPENDS+=	p5-File-Temp-[0-9]*:../../devel/p5-File-Temp
DEPENDS+=	p5-Spreadsheet-WriteExcel-[0-9]*:../../math/p5-Spreadsheet-WriteExcel
DEPENDS+=	p5-IO-CaptureOutput-[0-9]*:../../devel/p5-IO-CaptureOutput
#BUILD_DEPENDS+=	p5-Test-Strict-[0-9]*:../../devel/p5-Test-Strict

NO_CHECKSUM=	yes
USE_TOOLS+=	pax perl:run
USE_LANGUAGES=	# none
WRKSRC=		${WRKDIR}/ninka
PERL5_PACKLIST=	auto/Ninka/.packlist

# See https://github.com/dmgerman/ninka/pull/41
SUBST_CLASSES+=		regex
SUBST_STAGE.regex=	post-patch
SUBST_FILES.regex=	lib/Ninka/SentenceExtractor.pm
SUBST_SED.regex=	-e 's,1-2,1\,2,'

REPLACE_PERL+=	*/*.pl

INSTALLATION_DIRS=	bin

.include "../../wip/mk/git-package.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
