# $NetBSD$

DISTNAME=	Selenium-Remote-Driver-1.50
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www
MASTER_SITES=	http://cpan.metacpan.org/authors/id/T/TE/TEODESIAN/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://cpan.metacpan.org/authors/id/T/TE/TEODESIAN/
COMMENT=	Remote Test Driver for Selenium
LICENSE=	apache-2.0

REPLACE_PERL+=	driver-example.pl
REPLACE_PERL+=	blib/lib/Selenium/Remote/driver-example.pl


DEPENDS+=	p5-Moo-[0-9]*:../../devel/p5-Moo
DEPENDS+=	p5-IO-String-[0-9]*:../../devel/p5-IO-String
DEPENDS+=	p5-Archive-Zip-[0-9]*:../../archivers/p5-Archive-Zip
DEPENDS+=	p5-namespace-clean-[0-9]*:../../devel/p5-namespace-clean
DEPENDS+=	p5-XML-Simple-[0-9]*:../../textproc/p5-XML-Simple
DEPENDS+=	lsof-[0-9]*:../../sysutils/lsof

PERL5_PACKLIST=	auto/Selenium/Remote/Driver/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
