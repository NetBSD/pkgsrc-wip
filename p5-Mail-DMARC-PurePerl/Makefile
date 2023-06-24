# $NetBSD$

DISTNAME=	Mail-DMARC-1.20211209
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Mail/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/Mail::DMARC
COMMENT=	Perl implementation of DMARC
LICENSE=	${PERL5_LICENSE}

TOOL_DEPENDS+=	p5-Module-Build>=0.3601:../../devel/p5-Module-Build
TOOL_DEPENDS+=	p5-File-ShareDir-Install>=0.06:../../devel/p5-File-ShareDir-Install
TOOL_DEPENDS+=	p5-Module-Build>=0.3601:../../devel/p5-Module-Build
DEPENDS+=	p5-Config-Tiny>=0:../../devel/p5-Config-Tiny
DEPENDS+=	# TODO: p5-POSIX>=0
DEPENDS+=	# TODO: p5-perl>=5.10.0
DEPENDS+=	# TODO: p5-IO-Uncompress-Unzip>=0
DEPENDS+=	p5-Net-IP>=0:../../net/p5-Net-IP
DEPENDS+=	p5-Net-IDN-Encode>=0:../../textproc/p5-Net-IDN-Encode
DEPENDS+=	# TODO: p5-Sys-Syslog>=0
DEPENDS+=	# TODO: p5-IO-Compress-Zip>=0
DEPENDS+=	# TODO: p5-IO-File>=0
DEPENDS+=	# TODO: p5-Net-DNS-Resolver>=0
DEPENDS+=	p5-Socket6>=0.23:../../net/p5-Socket6
DEPENDS+=	# TODO: p5-Socket>=0
DEPENDS+=	p5-URI>=0:../../www/p5-URI
DEPENDS+=	# TODO: p5-Sys-Hostname>=0
DEPENDS+=	# TODO: p5-HTTP-Tiny>=0
DEPENDS+=	p5-Data-Dumper>=0:../../devel/p5-Data-Dumper
DEPENDS+=	# TODO: p5-IO-Uncompress-Gunzip>=0
DEPENDS+=	p5-Net-SSLeay>=0:../../security/p5-Net-SSLeay
DEPENDS+=	p5-Test-File-ShareDir>=0:../../devel/p5-Test-File-ShareDir
DEPENDS+=	p5-IO-Socket-SSL>=0:../../security/p5-IO-Socket-SSL
DEPENDS+=	p5-Email-MIME>=0:../../mail/p5-Email-MIME
DEPENDS+=	p5-Carp>=0:../../devel/p5-Carp
DEPENDS+=	p5-DBD-SQLite>=1.31:../../databases/p5-DBD-SQLite
DEPENDS+=	p5-Email-Sender>=0:../../mail/p5-Email-Sender
DEPENDS+=	p5-XML-LibXML>=0:../../textproc/p5-XML-LibXML
DEPENDS+=	p5-Regexp-Common>=2013031301:../../textproc/p5-Regexp-Common
DEPENDS+=	# TODO: p5-English>=0
DEPENDS+=	# TODO: p5-Getopt-Long>=0
DEPENDS+=	# TODO: p5-IO-Compress-Gzip>=0
DEPENDS+=	# TODO: p5-Encode>=0
DEPENDS+=	# TODO: p5-Email-Sender-Simple>=1.300032
DEPENDS+=	# TODO: p5-Pod-Usage>=0
DEPENDS+=	p5-Email-Simple>=0:../../mail/p5-Email-Simple
DEPENDS+=	p5-DBIx-Simple>=1.35:../../wip/p5-DBIx-Simple
DEPENDS+=	p5-File-ShareDir>=0:../../devel/p5-File-ShareDir
TEST_DEPENDS+=	p5-Test-Exception>=0:../../devel/p5-Test-Exception
TEST_DEPENDS+=	p5-Test-Output>=0:../../devel/p5-Test-Output
TEST_DEPENDS+=	p5-Test-File-ShareDir>=0:../../devel/p5-Test-File-ShareDir
TEST_DEPENDS+=	# TODO: p5-Test-More>=0

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/Mail/DMARC/.packlist
USE_LANGUAGES=		# none

license_default=	# TODO: perl (from Build.PL)

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
