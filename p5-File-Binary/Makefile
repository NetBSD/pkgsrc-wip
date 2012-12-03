# $NetBSD: Makefile,v 1.1 2012/12/03 16:36:03 othyro Exp $
#

DISTNAME=	File-Binary-1.7
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~simonw/File-Binary-1.7/lib/File/Binary.pm
COMMENT=	Binary file reading module
#LICENSE=	# XXX unknown

DEPENDS+=	p5-IO-stringy-[0-9]*:../../devel/p5-IO-stringy
DEPENDS+=	p5-IO-[0-9]*:../../devel/p5-IO
DEPENDS+=	p5-Test-Simple-[0-9]*:../../devel/p5-Test-Simple

PERL5_PACKLIST=	auto/File/Binary/.packlist
USE_LANGUAGES=	# none

post-install:
		${CHMOD} -x ${DESTDIR}${PREFIX}/${PERL5_SUB_INSTALLVENDORLIB}/File/Binary.pm


.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
