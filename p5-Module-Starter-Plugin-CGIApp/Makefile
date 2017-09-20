# $NetBSD: Makefile,v 1.2 2012/10/04 18:42:21 asau Exp $

DISTNAME=	Module-Starter-Plugin-CGIApp-0.44
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/J/JA/JALDHAR/

MAINTAINER=	ficovh@yahoo.com
HOMEPAGE=	http://search.cpan.org/~jaldhar/Module-Starter-Plugin-CGIApp/
COMMENT=	Template based module starter for CGI apps
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Module-Signature-[0-9]*:../../security/p5-Module-Signature
DEPENDS+=	p5-Pod-Coverage>=0.20:../../textproc/p5-Pod-Coverage
DEPENDS+=	p5-Test-Pod>=1.02:../../devel/p5-Test-Pod
DEPENDS+=	p5-HTML-Template-[0-9]*:../../www/p5-HTML-Template
DEPENDS+=	p5-Module-Starter-[0-9]*:../../devel/p5-Module-Starter
DEPENDS+=	p5-File-Copy-Recursive-[0-9]*:../../sysutils/p5-File-Copy-Recursive
DEPENDS+=	p5-File-DirCompare-[0-9]*:../../devel/p5-File-DirCompare
DEPENDS+=	p5-File-ShareDir-[0-9]*:../../devel/p5-File-ShareDir
DEPENDS+=	p5-Test-MockTime-[0-9]*:../../time/p5-Test-MockTime

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/Module/Starter/Plugin/CGIApp/.packlist
USE_LANGUAGES=		# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
