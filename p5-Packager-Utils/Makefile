# $NetBSD: Makefile,v 1.9 2015/07/12 18:57:34 thomasklausner Exp $

DISTNAME=	p5-Packager-Utils-0.0
PKGREVISION=	1
CATEGORIES=	pkgtools
MASTER_SITES=	#

MAINTAINER=	sno@NetBSD.org
HOMEPAGE=	https://github.com/rehsack/Packager-Utils
COMMENT=	Support packagers managing packages and upstream mapping

GIT_REPO=	https://github.com/rehsack/Packager-Utils.git

.include "../../wip/mk/git-package.mk"

# fatal: unable to access 'http://github.com/...': SSL certificate problem: unable to get local issuer certificate
# Add "-c http.sslVerify=false" to git command or,
PKGSRC_SETENV=		GIT_SSL_NO_VERIFY=true

INSTALLATION_DIRS=	share/examples/p5-Packager-Utils

PERL5_MODULE_TYPE=	MakeMaker
PERL5_PACKLIST=		auto/Packager/Utils/.packlist

DEPENDS+=	p5-Alien-Packages-[0-9]*:../../devel/p5-Alien-Packages
DEPENDS+=	p5-File-ShareDir-[0-9]*:../../devel/p5-File-ShareDir
DEPENDS+=	p5-File-ShareDir-Install-[0-9]*:../../devel/p5-File-ShareDir-Install
DEPENDS+=	p5-File-Find-Rule-[0-9]*:../../devel/p5-File-Find-Rule
DEPENDS+=	p5-File-Find-Rule-Age-[0-9]*:../../devel/p5-File-Find-Rule-Age
DEPENDS+=	p5-Hash-MoreUtils-[0-9]*:../../devel/p5-Hash-MoreUtils
DEPENDS+=	p5-List-MoreUtils-[0-9]*:../../devel/p5-List-MoreUtils
DEPENDS+=	p5-MooX-Cmd-[0-9]*:../../devel/p5-MooX-Cmd
DEPENDS+=	p5-MooX-Options-[0-9]*:../../devel/p5-MooX-Options
DEPENDS+=	p5-MooX-Roles-Pluggable-[0-9]*:../../devel/p5-MooX-Roles-Pluggable
DEPENDS+=	p5-Moose-[0-9]*:../../devel/p5-Moose
DEPENDS+=	p5-SQL-Translator-[0-9]*:../../databases/p5-SQL-Translator
DEPENDS+=	p5-DBIx-Class-[0-9]*:../../databases/p5-DBIx-Class
#DEPENDS+=	{perl>=5.004,p5-CPAN-[0-9]*}:../../devel/p5-CPAN
DEPENDS+=	p5-CPAN-DistnameInfo-[0-9]*:../../devel/p5-CPAN-DistnameInfo
DEPENDS+=	p5-Carp-Assert-[0-9]*:../../devel/p5-Carp-Assert
DEPENDS+=	p5-IO-CaptureOutput-[0-9]*:../../devel/p5-IO-CaptureOutput
DEPENDS+=	p5-File-pushd-[0-9]*:../../devel/p5-File-pushd
DEPENDS+=	p5-File-HomeDir-[0-9]*:../../devel/p5-File-HomeDir
DEPENDS+=	p5-Template-Toolkit-[0-9]*:../../www/p5-Template-Toolkit
DEPENDS+=	p5-MetaCPAN-API-[0-9]*:../../devel/p5-MetaCPAN-API
DEPENDS+=	p5-DBD-SQLite-[0-9]*:../../databases/p5-DBD-SQLite
DEPENDS+=	p5-Module-Pluggable>=4.8:../../devel/p5-Module-Pluggable

post-install:
	${INSTALL_DATA} ${WRKSRC}/etc/pkg_util.json ${DESTDIR}${PREFIX}/share/examples/p5-Packager-Utils

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
