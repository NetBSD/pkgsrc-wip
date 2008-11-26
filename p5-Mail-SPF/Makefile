# $Id: Makefile,v 1.6 2008/11/26 11:42:03 anielski Exp $
#

DISTNAME=	Mail-SPF-v2.006
PKGNAME=	p5-Mail-SPF-2.006
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Mail/}

MAINTAINER=	aniou@smutek.pl
HOMEPAGE=	http://search.cpan.org/~jmehnle/Mail-SPF-v2.006/
COMMENT=	Perl implementation of the Sender Policy Framework

BUILD_DEPENDS+= p5-Net-DNS-Resolver-Programmable-[0-9]*:../../wip/p5-Net-DNS-Resolver-Programmable
BUILD_DEPENDS+= p5-Test-Simple-[0-9]*:../../devel/p5-Test-Simple

DEPENDS+=	p5-version-[0-9]*:../../devel/p5-version
DEPENDS+=	p5-Error-[0-9]*:../../devel/p5-Error
DEPENDS+=	p5-NetAddr-IP>=4.000:../../net/p5-NetAddr-IP
DEPENDS+=	p5-Net-DNS>=0.58:../../net/p5-Net-DNS
DEPENDS+=	p5-URI-[0-9]*:../../www/p5-URI

SUBST_CLASSES+=		fix
SUBST_STAGE.fix=	pre-configure
SUBST_FILES.fix=	Build.PL
SUBST_SED.fix=		-e "s,^\(.*=> \)'/usr/sbin',\1 '${PREFIX}/usr/sbin',"
SUBST_MESSAGE.fix=	Fixing hardcoded spfd path

REPLACE_INTERPRETER+=	perl
REPLACE.perl.old=	.*/bin/perl
REPLACE.perl.new=	${PREFIX}/bin/perl
REPLACE_FILES.perl=	sbin/spfd

PKG_INSTALLATION_TYPES= overwrite pkgviews
PERL5_MODULE_TYPE= Module::Build

USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/Mail/SPF/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
