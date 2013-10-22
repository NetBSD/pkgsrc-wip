# $NetBSD: Makefile,v 1.1 2013/10/22 13:38:57 thomasklausner Exp $

DISTNAME=	p5-Packager-Utils-0.0
CATEGORIES=	pkgtools
MASTER_SITES=	#

MAINTAINER=	sno@NetBSD.org
HOMEPAGE=	https://github.com/rehsack/Packager-Utils
COMMENT=	Support packagers managing packages and upstream mapping

GIT_REPOSITORIES=		Packager-Utils
GIT_REPO.Packager-Utils=	https://github.com/rehsack/Packager-Utils.git
.include "../../wip/mk/git-package.mk"

# fatal: unable to access 'http://github.com/...': SSL certificate problem: unable to get local issuer certificate
# Add "-c http.sslVerify=false" to git command or,
PKGSRC_SETENV=		GIT_SSL_NO_VERIFY=true

WRKSRC=			${WRKDIR}/Packager-Utils
PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/Packager/Utils/.packlist

DEPENDS+=	p5-Module-CoreList-[0-9]*:../../devel/p5-Module-CoreList
DEPENDS+=	p5-File-ShareDir-[0-9]*:../../devel/p5-File-ShareDir
DEPENDS+=	p5-File-Find-Rule-[0-9]*:../../devel/p5-File-Find-Rule
DEPENDS+=	p5-File-Find-Rule-Age-[0-9]*:../../devel/p5-File-Find-Rule-Age
DEPENDS+=	p5-Hash-MoreUtils-[0-9]*:../../devel/p5-Hash-MoreUtils
DEPENDS+=	p5-List-MoreUtils-[0-9]*:../../devel/p5-List-MoreUtils
DEPENDS+=	p5-MooX-Cmd-[0-9]*:../../devel/p5-MooX-Cmd
DEPENDS+=	p5-MooX-Options-[0-9]*:../../devel/p5-MooX-Options
DEPENDS+=	p5-SQL-Translator-[0-9]*:../../databases/p5-SQL-Translator
DEPENDS+=	p5-DBIx-Class-[0-9]*:../../databases/p5-DBIx-Class
DEPENDS+=	p5-CPAN-[0-9]*:../../devel/p5-CPAN
DEPENDS+=	p5-CPAN-DistnameInfo-[0-9]*:../../devel/p5-CPAN-DistnameInfo
DEPENDS+=	p5-Carp-Assert-[0-9]*:../../devel/p5-Carp-Assert
DEPENDS+=	p5-IO-CaptureOutput-[0-9]*:../../devel/p5-IO-CaptureOutput
DEPENDS+=	p5-File-pushd-[0-9]*:../../devel/p5-File-pushd
DEPENDS+=	p5-File-HomeDir-[0-9]*:../../devel/p5-File-HomeDir
DEPENDS+=	p5-Template-Toolkit-[0-9]*:../../www/p5-Template-Toolkit
DEPENDS+=	p5-MetaCPAN-API-[0-9]*:../../devel/p5-MetaCPAN-API
DEPENDS+=	p5-DBD-SQLite-[0-9]*:../../databases/p5-DBD-SQLite

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
